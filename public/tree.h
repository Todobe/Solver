#pragma once

#include <vector>
#include <unordered_map>

struct WRRTree{
    int r;
    std::unordered_map<int, int> w;
    std::unordered_map<int, int> depth;
    std::unordered_map<int, std::vector<double>> m;
    std::unordered_map<int, std::vector<double>> beta;
    std::unordered_map<int, double> score;
};