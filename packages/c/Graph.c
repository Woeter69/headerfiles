#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

Graph* create_graph(int V) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->V = V;
    g->adj = (GraphNode**)malloc(sizeof(GraphNode*) * V);
    for (int i = 0; i < V; i++) g->adj[i] = NULL;
    return g;
}
void add_edge(Graph* g, int src, int dest, int weight) {
    GraphNode* node = (GraphNode*)malloc(sizeof(GraphNode));
    node->dest = dest;
    node->weight = weight;
    node->next = g->adj[src];
    g->adj[src] = node;

    // Undirected
    GraphNode* node2 = (GraphNode*)malloc(sizeof(GraphNode));
    node2->dest = src;
    node2->weight = weight;
    node2->next = g->adj[dest];
    g->adj[dest] = node2;
}

void bfs(Graph* g, int start) {
    int* visited = (int*)calloc(g->V, sizeof(int));
    int* queue = (int*)malloc(sizeof(int) * g->V);
    int front = 0, rear = 0;
    
    visited[start] = 1;
    queue[rear++] = start;
    
    printf("BFS: ");
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        GraphNode* temp = g->adj[u];
        while (temp) {
            if (!visited[temp->dest]) {
                visited[temp->dest] = 1;
                queue[rear++] = temp->dest;
            }
            temp = temp->next;
        }
    }
    printf("\n");
    free(visited);
    free(queue);
}

void dfs_util(Graph* g, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);
    GraphNode* temp = g->adj[v];
    while (temp) {
        if (!visited[temp->dest]) {
            dfs_util(g, temp->dest, visited);
        }
        temp = temp->next;
    }
}

void dfs(Graph* g, int start) {
    int* visited = (int*)calloc(g->V, sizeof(int));
    printf("DFS: ");
    dfs_util(g, start, visited);
    printf("\n");
    free(visited);
}

// Simple Union-Find for Kruskal
int find(int* parent, int i) {
    if (parent[i] == i) return i;
    return find(parent, parent[i]);
}
void Union(int* parent, int* rank, int x, int y) {
    int xroot = find(parent, x);
    int yroot = find(parent, y);
    if (rank[xroot] < rank[yroot]) parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot]) parent[yroot] = xroot;
    else {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}
typedef struct Edge { int u, v, w; } Edge;
int comp_edge(const void* a, const void* b) {
    return ((Edge*)a)->w - ((Edge*)b)->w;
}
void kruskal_mst(Graph* g) {
    int max_edges = g->V * g->V;
    Edge* edges = (Edge*)malloc(sizeof(Edge) * max_edges);
    int e_count = 0;
    for (int i = 0; i < g->V; i++) {
        GraphNode* temp = g->adj[i];
        while (temp) {
            if (i < temp->dest) {
                edges[e_count].u = i;
                edges[e_count].v = temp->dest;
                edges[e_count].w = temp->weight;
                e_count++;
            }
            temp = temp->next;
        }
    }
    qsort(edges, e_count, sizeof(Edge), comp_edge);
    int* parent = (int*)malloc(sizeof(int) * g->V);
    int* rank = (int*)calloc(g->V, sizeof(int));
    for (int i = 0; i < g->V; i++) parent[i] = i;
    
    printf("Kruskal MST: ");
    for (int i = 0; i < e_count; i++) {
        int u = edges[i].u, v = edges[i].v;
        int set_u = find(parent, u);
        int set_v = find(parent, v);
        if (set_u != set_v) {
            printf("(%d-%d:%d) ", u, v, edges[i].w);
            Union(parent, rank, set_u, set_v);
        }
    }
    printf("\n");
    free(parent); free(rank); free(edges);
}

void free_graph(Graph* g) {
    for (int i = 0; i < g->V; i++) {
        GraphNode* temp = g->adj[i];
        while (temp) {
            GraphNode* to_free = temp;
            temp = temp->next;
            free(to_free);
        }
    }
    free(g->adj);
    free(g);
}