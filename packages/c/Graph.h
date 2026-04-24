#ifndef GRAPH_H
#define GRAPH_H

typedef struct GraphNode {
    int dest;
    int weight;
    struct GraphNode* next;
} GraphNode;

typedef struct Graph {
    int V;
    GraphNode** adj;
} Graph;

Graph* create_graph(int V);
void add_edge(Graph* g, int src, int dest, int weight);
void bfs(Graph* g, int start);
void dfs(Graph* g, int start);
void kruskal_mst(Graph* g);
void free_graph(Graph* g);

#endif