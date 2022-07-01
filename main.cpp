#include "solver.h"

#include <iostream>
#include <fstream>
#include <functional>

struct node{
    int id,stamp,from,order;
    node(int id, int stamp, int from, int order):id(id),stamp(stamp),from(from),order(order){}
};

std::vector<node> block,truth,rumor;
std::vector<bool> is_block,is_truth,is_rumor;

void calc(const std::vector<Spread> &ret, const std::set<int> &Z, int t){
    for(auto it: ret){
      switch(it.st){
          case RUMOR:
              if(!is_rumor[it.v]){
                  is_rumor[it.v]=true;
                  is_truth[it.v]=false;
                  rumor.emplace_back(it.v,t,it.u,it.t);
                  if(it.u==-1){
                     // std::cout<<it.u<<" "<<it.v<<" "<<t<<" rumor"<<std::endl;
                  }
              }
              break;
          case TRUTH:
              if(!is_truth[it.v]){
                  is_truth[it.v]=true;
                  is_rumor[it.v]=false;
                  truth.emplace_back(it.v,t,it.u,it.t);
                  if(it.u==-1){
                      //std::cout<<it.u<<" "<<it.v<<" "<<t<<" truth"<<std::endl;
                  }
              }
              break;
          default:
          case INACTIVE:
              break;
      }
    }
    for(auto x: Z){
        if(!is_block[x]){
            is_block[x]=true;
            block.emplace_back(x,t,-1,0);
        }
    }
}

void output_to_file(const char* file_name){
    std::ofstream outputFile;

    outputFile.open(file_name, std::ios::out);
    if(!outputFile.is_open()){
        std::cout<< "Can't open or create file: "<<file_name<<" or permission denied."<<std::endl;
        return;
    }

    outputFile<<"Infected-nodes-(node,timestamp,from)"<<std::endl;
    for(auto x:rumor){
        outputFile<<x.id<<" "<<x.stamp<<" "<<x.from<<std::endl;
    }
    outputFile<<"Blocked-nodes-(node,timestamp)"<<std::endl;
    for(auto x:block){
        outputFile<<x.id<<" "<<x.stamp<<std::endl;
    }
    outputFile<<"KnowTruth-nodes-(node,timestamp,from)"<<std::endl;
    for(auto x:truth){
        outputFile<<x.id<<" "<<x.stamp<<" "<<x.from<<std::endl;
    }

    outputFile.close();

}

int main(int argc, char* argv[]) {
    Graph G("./data/graph200.in");
    std::mt19937 rng;
    rng.seed(std::random_device()());
    //rng.seed(12);
    G.generateLogin(rng);
    int threshold=10;
    std::vector<int> bigNodes;
    for(int i=0;i<G.V;i++){
        if(G.outEdges[i].size()>=threshold) bigNodes.emplace_back(i);
    }
    std::uniform_int_distribution uid(0, int(bigNodes.size()) - 1);
    std::cout<<"bignodes:"<<bigNodes.size()<<std::endl;
    char **ch;
    int alpha = strtol(argv[1], ch, 10);
    int K = strtol(argv[2],ch,10);
    int everyK = strtol(argv[3],ch,10);
    int rr = strtol(argv[4],ch,10);
    int S = strtol(argv[5],ch,10);
    int everyS = strtol(argv[6],ch,10);
    int setRumorRound = strtol(argv[7],ch,10);

    is_block.insert(is_block.end(), G.V, false);
    is_rumor.insert(is_rumor.end(), G.V, false);
    is_truth.insert(is_truth.end(), G.V, false);


    MultiRoundSolver mul(G), test(G);
    std::vector<Spread> ret, tmp;
    for (int k = 0; k < S; k += 1) {
        int t = uid(rng);
        while(bigNodes[t]==-1){
            t = uid(rng);
        }
        int u=bigNodes[t];
        bigNodes[t]=-1;
        mul.setRumor(u);
        ret.emplace_back(-1,u,-1,RUMOR);
    }
    calc(ret, mul.Z, 0);
    for (int i = 1; i <= rr; i += 1) {
        ret.clear();
        debug(i);

        if(i<=setRumorRound) {
            for (int k = 0; k < everyS; k += 1) {
                int t = uid(rng);
                while (bigNodes[t] == -1) {
                    t = uid(rng);
                }
                int u = bigNodes[t];
                bigNodes[t] = -1;
                mul.setRumor(u);
                test.setRumor(u);
                ret.emplace_back(-1, u, -1, RUMOR);
            }
        }

        if(i==1) mul.solve(rng,K,alpha);
        mul.solve(rng,everyK,alpha);
        mul.simulate(rng, alpha, ret);


        calc(ret, mul.Z, i);
        debug(mul.count(RUMOR), mul.count(TRUTH));
        debug(std::count(mul.G.spreaded.begin(),mul.G.spreaded.end(),1),std::count(mul.G.spreaded.begin(),mul.G.spreaded.end(),2));
        debug("");
    }
    output_to_file(argv[8]);
}