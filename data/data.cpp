#include <map>
#include <queue>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
    std::string input(argv[1]);
    std::string output(argv[2]);
    int n = atoi(argv[3]);
    std::ifstream fin(input);
    std::ofstream fout(output);
    int V, E;
    fin >> V >> E;
    if (n > V) n = V;
    std::vector<std::vector<int>> G(V + 1);
    for (int i = 0; i < 2 * E; i += 1) {
        int u, v;
        double _;
        fin >> u >> v >> _ >> _;
        if (u > V) std::cout << u << std::endl;
        G[u].push_back(v);
    }
    std::queue<int> q;
    std::map<int, int> map;
    int m = 0;
    map[1] = m ++;
    q.push(1);
    while (map.size() < n) {
        int u = q.front();
        q.pop();
        for (int v : G[u]) {
            if (not map.count(v) and map.size() < n) {
                map[v] = m ++;
                q.push(v);
            }
        }
    }
    std::vector<std::pair<int, int>> edges;
    for (int i = 1; i <= V; i += 1)
        for (int j : G[i])
            if (map.count(i) and map.count(j) and map[i] < map[j])
                edges.emplace_back(map[i], map[j]);
    fout << n << " " << edges.size() * 2 << "\n";
    for (auto [u, v] : edges) {
        fout << u << " " << v << "\n";
        fout << v << " " << u << "\n";
    }
}
