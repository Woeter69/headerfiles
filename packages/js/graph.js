class Graph {
    constructor() {
        this.adjacencyList = new Map();
    }
    addVertex(v) {
        this.adjacencyList.set(v, []);
    }
    addEdge(v, w, weight = 0) {
        if (!this.adjacencyList.has(v)) this.addVertex(v);
        if (!this.adjacencyList.has(w)) this.addVertex(w);
        this.adjacencyList.get(v).push({ node: w, weight });
        // Undirected graph
        this.adjacencyList.get(w).push({ node: v, weight });
    }
    bfs(startingNode) {
        let visited = new Set();
        let queue = [startingNode];
        let result = [];
        visited.add(startingNode);

        while (queue.length > 0) {
            let current = queue.shift();
            result.push(current);
            
            if(this.adjacencyList.has(current)) {
                let neighbors = this.adjacencyList.get(current);
                for (let neighbor of neighbors) {
                    if (!visited.has(neighbor.node)) {
                        visited.add(neighbor.node);
                        queue.push(neighbor.node);
                    }
                }
            }
        }
        return result;
    }
    dfs(startingNode) {
        let visited = new Set();
        let result = [];
        const dfsHelper = (vertex) => {
            visited.add(vertex);
            result.push(vertex);
            if(this.adjacencyList.has(vertex)) {
                let neighbors = this.adjacencyList.get(vertex);
                for (let neighbor of neighbors) {
                    if (!visited.has(neighbor.node)) {
                        dfsHelper(neighbor.node);
                    }
                }
            }
        };
        dfsHelper(startingNode);
        return result;
    }
    kruskalMST() {
        let edges = [];
        this.adjacencyList.forEach((neighbors, u) => {
            for (let v of neighbors) {
                if (u < v.node) {
                    edges.push({ u, v: v.node, weight: v.weight });
                }
            }
        });
        edges.sort((a, b) => a.weight - b.weight);

        let parent = {};
        const find = (i) => {
            if (parent[i] === i) return i;
            return find(parent[i]);
        };
        const union = (i, j) => {
            let rootI = find(i);
            let rootJ = find(j);
            parent[rootI] = rootJ;
        };

        this.adjacencyList.forEach((_, v) => parent[v] = v);

        let mst = [];
        for (let edge of edges) {
            let rootU = find(edge.u);
            let rootV = find(edge.v);
            if (rootU !== rootV) {
                mst.push(edge);
                union(rootU, rootV);
            }
        }
        return mst;
    }
}

module.exports = { Graph };
