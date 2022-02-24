#pragma once

#include "graph.h"
#include "tree.h"
#include "debug.h"

#include <set>
#include <unordered_map>

enum STATUS {
    INACTIVE,
    RUMOR,
    TRUTH
};

struct Spread{
    int u,v,t;
    STATUS st;
    Spread(int u,int v,int t,STATUS st);
};

struct Simulation {
    std::vector<STATUS> status;
    Graph G;
    void simulate(std::mt19937& rng, const Graph& G, const std::set<int>& R, const std::set<int>& Z, int alpha, std::vector<Spread> &ret, bool verbose = false);
    void simulate(std::mt19937& rng, Graph& G, std::vector<int>& spreaded, std::vector<STATUS>& status, int alpha, std::vector<Spread> &ret, bool verbose = false);
    int count(STATUS s) const;
};

struct Phi {
    double operator()(std::mt19937& rng, const Graph& G, const std::set<int>& R, const std::set<int>& Z, int alpha, std::vector<Spread> &ret, int time = 1000) const ;
};

struct Solver{
    Solver(const Graph& G);
    void computeThreatLevel(int alpha);
    void generateWRRTree(std::mt19937& rng, int alpha);
    void generateWRRTrees(std::mt19937& rng, int alpha, int time = 100000, int number = 1000);
    void extendZ(int k, int alpha);

    Graph G;
    std::set<int> R;
    std::set<int> Z;
    std::vector<double> q;
    std::vector<bool> E;
    std::vector<int> S;
    std::vector<std::vector<double>> threatLevel;
    std::vector<WRRTree> wrrTrees;
};

struct TIBSolver : Solver {
    TIBSolver(const Graph& G, const std::set<int>& R, int alpha);
    void solve(std::mt19937& rng, int k);

    int alpha;
};

struct MultiRoundSolver : Solver {
    MultiRoundSolver(const Graph& G);
    void solve(std::mt19937& rng, int k);
    void setRumor(int u);
    void solve(std::mt19937& rng, int k, int alpha);
    void simulate(std::mt19937& rng, int alpha, std::vector<Spread> &ret);
    int count(STATUS s) const;

    std::vector<STATUS> status;
};