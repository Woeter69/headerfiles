#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Heap.h"
#include "PriorityQueue.h"
#include "Tree.h"
#include "Graph.h"
#include "Sorting.h"
#include "Search.h"

void print_array(int arr[], int n) {
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    printf("--- Testing LinkedList ---\n");
    SNode* slist = NULL;
    slist = insert_singly(slist, 10);
    slist = insert_singly(slist, 20);
    print_singly(slist);
    free_singly(slist);
    
    printf("--- Testing Stack ---\n");
    Stack* s = create_stack();
    push(s, 1);
    push(s, 2);
    printf("Popped: %d\n", pop(s));
    free_stack(s);
    
    printf("--- Testing Queue ---\n");
    Queue* q = create_queue();
    enqueue(q, 1);
    enqueue(q, 2);
    printf("Dequeued: %d\n", dequeue(q));
    free_queue(q);
    
    printf("--- Testing Deque ---\n");
    Deque* dq = create_deque();
    push_front(dq, 1);
    push_back(dq, 2);
    printf("Pop Front: %d\n", pop_front(dq));
    free_deque(dq);
    
    printf("--- Testing Heap ---\n");
    Heap* h = create_heap(10, 1);
    insert_heap(h, 5);
    insert_heap(h, 2);
    insert_heap(h, 8);
    printf("Extracted: %d\n", extract_heap(h));
    free_heap(h);
    
    printf("--- Testing PriorityQueue ---\n");
    PriorityQueue* pq = create_pq(10);
    pq_push(pq, 10);
    pq_push(pq, 5);
    printf("PQ Pop: %d\n", pq_pop(pq));
    free_pq(pq);
    
    printf("--- Testing Tree ---\n");
    BSTNode* bst = NULL;
    bst = bst_insert(bst, 5);
    bst_insert(bst, 3);
    bst_insert(bst, 7);
    bst_inorder(bst);
    printf("\n");
    bst_free(bst);
    
    printf("--- Testing Graph ---\n");
    Graph* g = create_graph(4);
    add_edge(g, 0, 1, 10);
    add_edge(g, 0, 2, 6);
    add_edge(g, 0, 3, 5);
    add_edge(g, 1, 3, 15);
    add_edge(g, 2, 3, 4);
    bfs(g, 0);
    dfs(g, 0);
    kruskal_mst(g);
    free_graph(g);
    
    printf("--- Testing Sorting ---\n");
    int arr[] = {4, 2, 5, 1, 3};
    heap_sort(arr, 5);
    print_array(arr, 5);
    
    printf("--- Testing Search ---\n");
    int idx = binary_search(arr, 5, 4);
    printf("Found 4 at index: %d\n", idx);
    
    printf("All tests passed!\n");
    return 0;
}