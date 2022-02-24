#pragma once

#include <random>
#include <vector>
#include <string>

struct Edge{
    int u, v;
    double p;
};

struct Graph{
    Graph();
    Graph(const std::string& path);
    void generateLogin(std::mt19937& rng);
    double online(int v, int s) const;

    int V;
    int E;
    std::vector<Edge> edges;
    std::vector<int> spreaded;
    std::vector<std::vector<int>> inEdges;
    std::vector<std::vector<int>> outEdges;
    std::vector<double> login;
};