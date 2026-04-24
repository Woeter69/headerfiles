namespace csharp_packages;
using System.Collections.Generic;
using System;

public class Graph {
    private readonly Dictionary<int, List<int>> _adj = new();

    public void AddEdge(int u, int v, bool directed = false) {
        if (!_adj.ContainsKey(u)) _adj[u] = new List<int>();
        if (!_adj.ContainsKey(v)) _adj[v] = new List<int>();
        _adj[u].Add(v);
        if (!directed) _adj[v].Add(u);
    }

    public List<int> BFS(int start) {
        var res = new List<int>();
        var q = new System.Collections.Generic.Queue<int>();
        var visited = new HashSet<int>();
        q.Enqueue(start);
        visited.Add(start);

        while (q.Count > 0) {
            int curr = q.Dequeue();
            res.Add(curr);
            if (_adj.ContainsKey(curr)) {
                foreach (var n in _adj[curr]) {
                    if (!visited.Contains(n)) {
                        visited.Add(n);
                        q.Enqueue(n);
                    }
                }
            }
        }
        return res;
    }

    public List<int> DFS(int start) {
        var res = new List<int>();
        var visited = new HashSet<int>();
        void DfsRec(int u) {
            visited.Add(u);
            res.Add(u);
            if (_adj.ContainsKey(u)) {
                foreach (var n in _adj[u]) {
                    if (!visited.Contains(n)) {
                        DfsRec(n);
                    }
                }
            }
        }
        DfsRec(start);
        return res;
    }
}

public class Edge : IComparable<Edge> {
    public int U, V, Weight;
    public Edge(int u, int v, int w) { U = u; V = v; Weight = w; }
    public int CompareTo(Edge? other) => other == null ? 1 : Weight.CompareTo(other.Weight);
}

public class KruskalMST {
    class DisjointSet {
        int[] parent, rank;
        public DisjointSet(int n) {
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) parent[i] = i;
        }
        public int Find(int i) {
            if (parent[i] != i) parent[i] = Find(parent[i]);
            return parent[i];
        }
        public void Union(int x, int y) {
            int xroot = Find(x), yroot = Find(y);
            if (rank[xroot] < rank[yroot]) parent[xroot] = yroot;
            else if (rank[xroot] > rank[yroot]) parent[yroot] = xroot;
            else { parent[yroot] = xroot; rank[xroot]++; }
        }
    }

    public static List<Edge> FindMST(List<Edge> edges, int verticesCount) {
        edges.Sort();
        var ds = new DisjointSet(verticesCount);
        var mst = new List<Edge>();
        foreach (var e in edges) {
            int x = ds.Find(e.U);
            int y = ds.Find(e.V);
            if (x != y) {
                mst.Add(e);
                ds.Union(x, y);
            }
        }
        return mst;
    }
}