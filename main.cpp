#include "solver.h"

#include <iostream>
#include <fstream>

struct node{
    int id,stamp,from;
    node(int id, int stamp, int from):id(id),stamp(stamp),from(from){}
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
                  rumor.emplace_back(it.v,t,it.u);
                  if(it.u==-1){
                      std::cout<<it.u<<" "<<it.v<<" "<<t<<std::endl;
                  }
              }
              break;
          case TRUTH:
              if(!is_truth[it.v]){
                  is_truth[it.v]=true;
                  is_rumor[it.v]=false;
                  truth.emplace_back(it.v,t,it.u);
                  if(it.u==-1){
                      std::cout<<it.u<<" "<<it.v<<" "<<t<<std::endl;
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
            block.emplace_back(x,t,-1);
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

int main() {
    Graph G("./data/weibo500");
    std::mt19937 rng;
    rng.seed(std::random_device()());
    G.generateLogin(rng);
    std::uniform_int_distribution uid(0, G.V - 1);
    int alpha = 10;
//    if (0) {
//        std::set<int> R;
//        while (R.size() < 30) {
//            R.insert(uid(rng));
//        }
//        TIBSolver tib(G, R, alpha);
//        tib.solve(rng, 30);
//        debug(Phi()(rng, G, R, tib.Z, alpha), Phi()(rng, G, R, {}, alpha));
//    }

    is_block.insert(is_block.end(), G.V, false);
    is_rumor.insert(is_rumor.end(), G.V, false);
    is_truth.insert(is_truth.end(), G.V, false);


    MultiRoundSolver mul(G), test(G);
    std::vector<Spread> ret, tmp;
    for (int i = 0; i < 25; i += 1) {
        ret.clear();
        debug(i);
        for (int k = 0; k < 20; k += 1) {
            int u = uid(rng);
            mul.setRumor(u);
            test.setRumor(u);
            ret.emplace_back(-1,u,-1,RUMOR);
        }
        mul.solve(rng, 10, alpha);
        test.solve(rng, 0, alpha);
        mul.simulate(rng, alpha, ret);
        test.simulate(rng, alpha, tmp);

        calc(ret, mul.Z, i);
        debug(mul.count(RUMOR), test.count(RUMOR));
        debug(mul.count(TRUTH), test.count(TRUTH));
        debug("");
    }
    output_to_file("output.txt");
}