class Graph:
    def __init__(self):
        self.adj = {}
    
    def add_edge(self, u, v, weight=1):
        if u not in self.adj: self.adj[u] = []
        if v not in self.adj: self.adj[v] = []
        self.adj[u].append((v, weight))
        self.adj[v].append((u, weight)) # Undirected
        
    def bfs(self, start):
        if start not in self.adj: return []
        visited = set([start])
        queue = [start]
        res = []
        while queue:
            node = queue.pop(0)
            res.append(node)
            for neighbor, _ in self.adj.get(node, []):
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)
        return res

    def dfs(self, start):
        if start not in self.adj: return []
        visited = set()
        res = []
        def _dfs(node):
            visited.add(node)
            res.append(node)
            for neighbor, _ in self.adj.get(node, []):
                if neighbor not in visited:
                    _dfs(neighbor)
        _dfs(start)
        return res

    def kruskal_mst(self):
        edges = []
        for u in self.adj:
            for v, w in self.adj[u]:
                if u < v:
                    edges.append((w, u, v))
        edges.sort()
        
        parent = {}
        def find(i):
            if parent[i] == i:
                return i
            parent[i] = find(parent[i])
            return parent[i]
            
        def union(i, j):
            root_i = find(i)
            root_j = find(j)
            if root_i != root_j:
                parent[root_i] = root_j
                
        for node in self.adj:
            parent[node] = node
            
        mst = []
        for w, u, v in edges:
            if find(u) != find(v):
                union(u, v)
                mst.append((u, v, w))
        return mst
