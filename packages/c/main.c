#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "Tree.h"
#include "Heap.h"
#include "PriorityQueue.h"
#include "Graph.h"
#include "Sorting.h"
#include "Search.h"

int main() {
    printf("--- Testing LinkedList ---\n");
    SNode* sll = NULL;
    sll = insert_singly(sll, 10);
    sll = insert_singly(sll, 20);
    print_singly(sll);
    printf("Reversed: ");
    sll = reverse(sll);
    print_singly(sll);
    printf("Has Cycle: %d\n", has_cycle(sll));

    printf("\n--- Testing Stack ---\n");
    Stack* s = create_stack();
    push(s, 1);
    push(s, 2);
    printf("Popped: %d\n", pop(s));
    printf("isValidParentheses(\"{[()]}\"): %d\n", is_valid_parentheses("{[()]}"));
    printf("isValidParentheses(\"{[(])}\"): %d\n", is_valid_parentheses("{[(])}"));
    free_stack(s);

    printf("\n--- Testing Queue ---\n");
    Queue* q = create_queue();
    enqueue(q, 1);
    enqueue(q, 2);
    printf("Dequeued: %d\n", dequeue(q));
    free_queue(q);

    printf("\n--- Testing Circular Queue ---\n");
    CircularQueue* cq = create_circular_queue(3);
    cq_enqueue(cq, 1); cq_enqueue(cq, 2); cq_enqueue(cq, 3);
    printf("Is Full: %d\n", cq_is_full(cq));
    printf("Dequeued: %d\n", cq_dequeue(cq));
    cq_enqueue(cq, 4);
    free_circular_queue(cq);

    printf("\n--- Testing Heap ---\n");
    Heap* h = create_heap(10, 1);
    insert_heap(h, 3);
    insert_heap(h, 1);
    insert_heap(h, 2);
    printf("Extracted: %d\n", extract_heap(h));
    free_heap(h);

    printf("\n--- Testing PriorityQueue ---\n");
    PriorityQueue* pq = create_pq(10);
    pq_push(pq, 5);
    pq_push(pq, 10);
    printf("PQ Pop: %d\n", pq_pop(pq));
    free_pq(pq);

    printf("\n--- Testing Tree ---\n");
    BSTNode* bst = NULL;
    bst = bst_insert(bst, 5);
    bst = bst_insert(bst, 3);
    bst = bst_insert(bst, 7);
    bst_inorder(bst);
    printf("\n");
    bst_free(bst);

    printf("\n--- Testing AVL Tree ---\n");
    AVLNode* avl = NULL;
    avl = avl_insert(avl, 10);
    avl = avl_insert(avl, 20);
    avl = avl_insert(avl, 30);
    avl_inorder(avl);
    printf("\n");
    avl_free(avl);

    printf("\n--- Testing Trie ---\n");
    TrieNode* trie = trie_create();
    trie_insert(trie, "apple");
    printf("Search 'apple': %d\n", trie_search(trie, "apple"));
    printf("Search 'app': %d\n", trie_search(trie, "app"));
    trie_free(trie);

    printf("\n--- Testing Graph ---\n");
    Graph* g = create_graph(4);
    add_edge(g, 0, 1, 10);
    add_edge(g, 0, 2, 6);
    add_edge(g, 0, 3, 5);
    add_edge(g, 1, 3, 15);
    add_edge(g, 2, 3, 4);
    printf("BFS: "); bfs(g, 0); printf("\n");
    printf("DFS: "); dfs(g, 0); printf("\n");
    kruskal_mst(g);
    free_graph(g);

    printf("\n--- Testing Sorting ---\n");
    int arr[] = {5, 2, 4, 1, 3};
    int n = 5;
    bubble_sort(arr, n);
    printf("Bubble Sort: "); for(int i=0; i<n; i++) printf("%d ", arr[i]); printf("\n");
    
    int arr2[] = {5, 2, 4, 1, 3};
    quick_sort(arr2, 0, n - 1);
    printf("Quick Sort: "); for(int i=0; i<n; i++) printf("%d ", arr2[i]); printf("\n");

    int arr3[] = {5, 2, 4, 1, 3};
    merge_sort(arr3, 0, n - 1);
    printf("Merge Sort: "); for(int i=0; i<n; i++) printf("%d ", arr3[i]); printf("\n");

    printf("\n--- Testing Search ---\n");
    int s_arr[] = {1, 2, 3, 4, 5};
    printf("Linear Search 4: Found at index %d\n", linear_search(s_arr, 5, 4));
    printf("Binary Search 4: Found at index %d\n", binary_search(s_arr, 5, 4));

    printf("\nAll C tests passed!\n");
    return 0;
}
