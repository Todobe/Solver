#include <iostream>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <map>
using namespace std;

int main(int argc,char* argv[]){
    srand(time(0));
    int n=200, m=4000;
    if(argc>2){
        n=atoi(argv[2]);
        m=atoi(argv[3]);
    }
    std::ofstream fout;
    fout.open(argv[1],ios::out);
    map<pair<int,int>,bool> M;
    for(int i=1;i<=m;i++){
        if(M.size()==n*(n-1)) break;
        int u=rand()%n,v=rand()%n;
        while(M.find(make_pair(u,v))!=M.end() || u==v){
            u=rand()%n,v=rand()%n;
        }
        M[make_pair(u,v)]=true;
    }
    fout<<n<<" "<<M.size()<<endl;
    for(auto it:M){
        fout<<it.first.first<<" "<<it.first.second<<endl;
    }
    fout.close();
}