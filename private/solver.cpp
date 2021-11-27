#include "solver.h"

#include <queue>
#include <functional>

void Simulation::simulate(std::mt19937& rng, const Graph& G, const std::set<int>& R, const std::set<int>& Z, int alpha, bool verbose) {
    this->G = G;
    status.resize(G.V, INACTIVE);
    for (int x : R) {
        status[x] = RUMOR;
    }
    for (int x : Z) {
        status[x] = TRUTH;
    }
    simulate(rng, this->G, this->G.spreaded, status, alpha, verbose);
}
void Simulation::simulate(std::mt19937& rng, Graph& G, std::vector<bool>& spreaded, std::vector<STATUS>& status, int alpha, bool verbose) {
    std::uniform_real_distribution urd;
    for (int time = 1; time <= alpha; time += 1) {
        std::vector<bool> logined(G.V);
        for (int i = 0; i < G.V; i += 1) {
            logined[i] = urd(rng) < G.login[i];
        }
        for (STATUS s : {TRUTH, RUMOR}) {
            for (int i = 0; i < G.E; i += 1) {
                auto [u, v, p] = G.edges[i];
                if (not spreaded[i] and logined[v] and status[u] == s) {
                    spreaded[i] = true;
                    if (urd(rng) < p) {
                        if (verbose) {
                            std::cout << (s == RUMOR ? "Rumor" : "Truth") << " from " << u << " to " << v << " at " << time << std::endl;
                        }
                        status[v] = s;
                    }
                }
            }   
        }
    }
}

int Simulation::count(STATUS s) const {
    return std::count(status.begin(), status.end(), s);
}


double Phi::operator()(std::mt19937& rng, const Graph& G, const std::set<int>& R, const std::set<int>& Z, int alpha, int time) const {
    double res = 0;
    for (int i = 0; i < time; i += 1) {
        Simulation test;
        test.simulate(rng, G, R, Z, alpha);
        res += test.count(RUMOR);
    }
    return res / time;
}

Solver::Solver(const Graph& G) : G(G) {

}

void Solver::computeThreatLevel(int alpha) {
    int dfsTime = 0;
    std::vector sigma(G.V, -1), parent(G.V, -1), depth(G.V, -1);
    std::function<void(int, int)> dfs = [&](int u, int hop){
        depth[u] = hop;
        sigma[u] = dfsTime ++;
        if (hop == alpha) {
            return;
        }
        for (int i : G.outEdges[u]) {
            if (not G.spreaded[i]) {
                int v = G.edges[i].v;
                if (not R.count(v) and not Z.count(v) and sigma[v] == -1) {
                    parent[v] = u;
                    dfs(v, hop + 1);
                }
            }
        }
    };
    for (int u : R) dfs(u, 0);
    E.resize(G.E);
    std::vector<int> inDegree(G.V);
    for (int i = 0; i < G.E; i += 1) {
        if (not G.spreaded[i]) {
            auto [u, v, p] = G.edges[i];
            if (sigma[u] == -1 or sigma[v] == -1) {
                continue;
            }
            if (parent[v] == u) {
                E[i] = true;
                inDegree[v] += 1;
            }
            if (sigma[u] >= sigma[v]) {
                int pu = u, pv = v;
                if (depth[pu] < depth[pv]) {
                    std::swap(pu, pv);
                }
                while (depth[pu] > depth[pv]) {
                    pu = parent[pu];
                }
                if (pu != pv) {
                    E[i] = true;
                    inDegree[v] += 1;
                }
            }
        }
    }
    for (int i = 0; i < G.V; i += 1) {
        if (sigma[i] != -1 and inDegree[i] == 0) {
            S.push_back(i);
        }
    }
    for (int i = 0; i < (int)S.size(); i += 1) {
        int u = S[i];
        for (int j : G.outEdges[u]) {
            if (E[j]) {
                int v = G.edges[j].v;
                if (not (inDegree[v] -= 1)) {
                    S.push_back(v);
                }
            }
        }
    }
    q.resize(G.E);
    threatLevel.resize(G.V);
    for (int i = (int)S.size() - 1; i >= 0; i -= 1) {
        int u = S[i];
        for (int j : G.outEdges[u]) {
            if (E[j]) {
                q[j] = G.edges[j].p;
                for (int k : G.inEdges[u]) {
                    if (E[k] and G.edges[k].u != u) {
                        q[j] *= 1 - G.edges[k].p;
                    }
                }
            }
        }
        threatLevel[u].resize(alpha + 1);
        threatLevel[u][0] = 1;
        for (int t = 1; t <= alpha; t += 1) {
            for (int i : G.outEdges[u]){
                if (E[i]) {
                    int v = G.edges[i].v;
                    for (int s = 1; s <= t; s += 1) {
                        threatLevel[u][t] += q[i] * G.online(v, s) * threatLevel[v][t - s];
                    }
                }
            }
        }
        //debug(u, threat_level[u]);
    }
}

void Solver::generateWRRTree(std::mt19937& rng, int alpha) {
    WRRTree tree;
    int r = tree.r = S[std::uniform_int_distribution(0, (int)S.size() - 1)(rng)];
    std::queue<int> A;
    std::unordered_map<int, std::set<int>> CR;
    A.push(r);
    tree.w[r] = -1;
    tree.depth[r] = 0;
    std::uniform_real_distribution urd;
    while (not A.empty()) {
        int v = A.front();
        A.pop();
        tree.m[v].resize(alpha + 1);
        if (v == r) {
            tree.m[v][0] = 1;
        }
        else {
            int w = tree.w[v];
            for (int i = tree.depth[v]; i <= alpha; i += 1) {
                for (int j = 1; j <= i; j += 1) {
                    tree.m[v][i] += G.online(w, j) * tree.m[w][i - j];
                }
            }
        }
        if (not R.count(v)) {
            if (tree.depth[v] < alpha) {
                for (int i : G.inEdges[v]) {
                    int u = G.edges[i].u;
                    if (not G.spreaded[i] and urd(rng) < G.edges[i].p and not threatLevel[u].empty() and not tree.depth.count(u)) {
                        tree.w[u] = v;
                        tree.depth[u] = tree.depth[v] + 1;
                        A.push(u);
                    }
                }
            }
        }
        else {
            for (int p = v; p != -1; p = tree.w[p]) {
                CR[p].insert(v);
            }
        }
    }
    if (CR[r].size()) {
        for (auto [u, _] : tree.w) {
            if (not R.count(u)) {
                tree.beta[u] = tree.m[u];
                for (int w : CR[r]) {
                    if (not CR[u].count(w)) {
                        double prod = 1;
                        for (int t = 1; t <= alpha; t += 1) {
                            prod *= 1 - tree.m[w][t - 1];
                            tree.beta[u][t] *= prod;
                        }
                    }
                }
                for (int t = 1; t <= alpha; t += 1) {
                    for (int j = 0; j <= alpha - t; j += 1) {
                        tree.score[u] += tree.beta[u][t] * threatLevel[u][j];
                    }
                }
            }
        }
        wrrTrees.push_back(tree);
    }
}

void Solver::generateWRRTrees(std::mt19937& rng, int alpha, int time, int number) {
    for (int i = 0; i < time and (int)wrrTrees.size() < number; i += 1) {
        generateWRRTree(rng, alpha);
    }
}

void Solver::extendZ(int k, int alpha) {
    while (Z.size() < k) {
        int u = -1;
        double score = 0;
        for (auto& tree : wrrTrees) {
            for (auto& [cu, cscore] : tree.score) {
                if (cscore > score) {
                    score = cscore;
                    u = cu;
                }
            }
        }
        if (u == -1) break;
        Z.insert(u);
        for (int i : G.inEdges[u]) {
            if (E[i]) {
                int v = G.edges[i].v;
                for (int t = 1; t <= alpha; t += 1) {
                    for (int s = 1; s <= t; s += 1) {
                        threatLevel[v][t] -= q[i] * G.online(u, s) * threatLevel[u][t - s];
                    }
                }
                for (auto& tree : wrrTrees) {
                    if (tree.r == v) {
                        for (auto [w, _] : tree.w) {
                            if (not R.count(u) and not Z.count(u)) {
                                tree.score[w] = 0;
                                for (int t = 1; t <= alpha; t += 1) {
                                    for (int j = 0; j <= alpha - t; j += 1) {
                                        tree.score[w] += tree.beta[w][t] * threatLevel[w][j];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        for (auto& tree : wrrTrees) {
            if (tree.w.count(u)) {
                tree.score[u] = 0;
                std::unordered_map<int, std::set<int>> CR;
                for (auto [w, _] : tree.w) {
                    if (R.count(w) or Z.count(w)) {
                        for (int p = w; p != -1; p = tree.w[p]) {
                            CR[p].insert(w);
                        }
                    }
                }
                for (auto [u, _] : tree.w) {
                    if (not R.count(u) and not Z.count(u)) {
                        tree.score[u] = 0;
                        tree.beta[u] = tree.m[u];
                        for (int w : CR[tree.r]) {
                            if (not CR[u].count(w)) {
                                double prod = 1;
                                for (int t = 1; t <= alpha; t += 1) {
                                    prod *= 1 - tree.m[w][t - 1];
                                    tree.beta[u][t] *= prod;
                                }
                            }
                        }
                        for (int t = 1; t <= alpha; t += 1) {
                            for (int j = 0; j <= alpha - t; j += 1) {
                                tree.score[u] += tree.beta[u][t] * threatLevel[u][j];
                            }
                        }
                    }
                }
            }
        }
    }
}

TIBSolver::TIBSolver(const Graph& G, const std::set<int>& R, int alpha) : Solver(G), alpha(alpha){
    Solver::R = R;
}

void TIBSolver::solve(std::mt19937& rng, int k) {
    computeThreatLevel(alpha);
    generateWRRTrees(rng, alpha);
    extendZ(k, alpha);
    std::uniform_int_distribution uid(0, G.V - 1);
    for (int i = 0; i < k and Z.size() < k; i += 1) {
        Z.insert(uid(rng));
    }
    
}

MultiRoundSolver::MultiRoundSolver(const Graph& G) : Solver(G), status(G.V, INACTIVE) {
}

void MultiRoundSolver::setRumor(int u) {
    if (status[u] == INACTIVE) {
        status[u] = RUMOR;
        R.insert(RUMOR);
    }
}

void MultiRoundSolver::solve(std::mt19937& rng, int k, int alpha) {
    S.clear();
    E.clear();
    q.clear();
    threatLevel.clear();
    wrrTrees.clear();
    computeThreatLevel(alpha);
    generateWRRTrees(rng, alpha);
    int K = Z.size() + k;
    extendZ(K, alpha);
    std::uniform_int_distribution uid(0, G.V - 1);
    for (int i = 0; i < K and Z.size() < K; i += 1) {
        Z.insert(uid(rng));
    }
}

void MultiRoundSolver::simulate(std::mt19937& rng, int alpha) {
    for (int u : Z) {
        if (status[u] == INACTIVE) {
            status[u] = TRUTH;
        }
    }
    Simulation().simulate(rng, G, G.spreaded, status, alpha);
}

int MultiRoundSolver::count(STATUS s) const {
    return std::count(status.begin(), status.end(), s);
}