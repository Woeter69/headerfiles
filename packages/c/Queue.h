#ifndef QUEUE_H
#define QUEUE_H
#include "LinkedList.h"

typedef struct Queue {
    SNode* front;
    SNode* rear;
} Queue;

Queue* create_queue();
void enqueue(Queue* q, int val);
int dequeue(Queue* q);
void free_queue(Queue* q);

typedef struct Deque {
    DNode* front;
    DNode* rear;
} Deque;

Deque* create_deque();
void push_front(Deque* q, int val);
void push_back(Deque* q, int val);
int pop_front(Deque* q);
int pop_back(Deque* q);
void free_deque(Deque* q);

typedef struct CircularQueue {
    int* data;
    int front;
    int rear;
    int size;
    int capacity;
} CircularQueue;

CircularQueue* create_circular_queue(int capacity);
int cq_enqueue(CircularQueue* q, int val);
int cq_dequeue(CircularQueue* q);
int cq_is_full(CircularQueue* q);
int cq_is_empty(CircularQueue* q);
void free_circular_queue(CircularQueue* q);

#endif