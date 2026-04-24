#include "PriorityQueue.h"
#include <stdlib.h>

PriorityQueue* create_pq(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->h = create_heap(capacity, 1);
    return pq;
}
void pq_push(PriorityQueue* pq, int val) {
    insert_heap(pq->h, val);
}
int pq_pop(PriorityQueue* pq) {
    return extract_heap(pq->h);
}
void free_pq(PriorityQueue* pq) {
    free_heap(pq->h);
    free(pq);
}