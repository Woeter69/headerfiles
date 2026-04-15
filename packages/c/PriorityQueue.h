#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include "Heap.h"

typedef struct PriorityQueue {
    Heap* h;
} PriorityQueue;

PriorityQueue* create_pq(int capacity);
void pq_push(PriorityQueue* pq, int val);
int pq_pop(PriorityQueue* pq);
void free_pq(PriorityQueue* pq);
#endif