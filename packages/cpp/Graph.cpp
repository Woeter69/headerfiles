#include "Graph.hpp"
#include <iostream>
#include <queue>
#include <algorithm>

void Graph::addEdge(int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w}); // Undirected
}

void Graph::BFS(int start) const {
    std::unordered_map<int, bool> visited;
    std::queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        std::cout << curr << " ";

        if (adj.find(curr) != adj.end()) {
            for (const auto& edge : adj.at(curr)) {
                if (!visited[edge.first]) {
                    visited[edge.first] = true;
                    q.push(edge.first);
                }
            }
        }
    }
    std::cout << "\n";
}

void Graph::DFS(int start) const {
    std::unordered_map<int, bool> visited;
    std::vector<int> stack;
    stack.push_back(start);

    while (!stack.empty()) {
        int curr = stack.back();
        stack.pop_back();

        if (!visited[curr]) {
            std::cout << curr << " ";
            visited[curr] = true;
            if (adj.find(curr) != adj.end()) {
                for (const auto& edge : adj.at(curr)) {
                    if (!visited[edge.first]) {
                        stack.push_back(edge.first);
                    }
                }
            }
        }
    }
    std::cout << "\n";
}

struct Edge {
    int u, v, w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int Graph::KruskalMST() const {
    std::vector<Edge> edges;
    for (const auto& p : adj) {
        for (const auto& edge : p.second) {
            if (p.first < edge.first) {
                edges.push_back({p.first, edge.first, edge.second});
            }
        }
    }

    std::sort(edges.begin(), edges.end());

    std::unordered_map<int, int> parent;
    
    auto find = [&](int i, auto& find_ref) -> int {
        if (parent.find(i) == parent.end()) {
            parent[i] = i;
        }
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find_ref(parent[i], find_ref);
    };

    auto unite = [&](int i, int j, auto& find_ref) -> void {
        int rootI = find_ref(i, find_ref);
        int rootJ = find_ref(j, find_ref);
        if (rootI != rootJ) {
            parent[rootI] = rootJ;
        }
    };

    int mstWeight = 0;
    for (const auto& e : edges) {
        int rootU = find(e.u, find);
        int rootV = find(e.v, find);

        if (rootU != rootV) {
            mstWeight += e.w;
            unite(rootU, rootV, find);
        }
    }

    return mstWeight;
}
