#pragma once
#include <vector>
#include <unordered_map>

class Graph {
    std::unordered_map<int, std::vector<std::pair<int, int>>> adj; // u -> {v, weight}
public:
    void addEdge(int u, int v, int w = 1);
    void BFS(int start) const;
    void DFS(int start) const;
    int KruskalMST() const;
};
