#include "graph.h"

#include <fstream>
#include <functional>

Graph::Graph() {
    
}

Graph::Graph(const std::string& path) {
    std::ifstream fin(path);
    fin >> V >> E;
    edges.resize(E);
    spreaded.resize(E);
    inEdges.resize(V);
    outEdges.resize(V);
    login.resize(V);
    for (int i = 0; i < E; i ++) {
        auto& [u, v, p] = edges[i];
        fin >> u >> v;
        inEdges[v].push_back(i);
        outEdges[u].push_back(i);
    }
    for (int i = 0; i < E; i += 1) {
        if (inEdges[edges[i].v].size()) {
            edges[i].p =std::max(0.2, 1.0 / inEdges[edges[i].v].size());
        }
    }

}

void Graph::generateLogin(std::mt19937& rng) {
    std::uniform_real_distribution<> urd(0.2, 1);
    for (double& p : login) p = urd(rng);
}

double Graph::online(int v, int s) const {
    return pow(1 - login[v], s - 1) * login[v];
}