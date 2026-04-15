#include "Queue.h"
#include <stdlib.h>

Queue* create_queue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}
void enqueue(Queue* q, int val) {
    SNode* node = (SNode*)malloc(sizeof(SNode));
    node->data = val;
    node->next = NULL;
    if (q->rear) {
        q->rear->next = node;
        q->rear = node;
    } else {
        q->front = q->rear = node;
    }
}
int dequeue(Queue* q) {
    if (!q->front) return -1;
    SNode* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (!q->front) q->rear = NULL;
    free(temp);
    return val;
}
void free_queue(Queue* q) {
    free_singly(q->front);
    free(q);
}

Deque* create_deque() {
    Deque* q = (Deque*)malloc(sizeof(Deque));
    q->front = q->rear = NULL;
    return q;
}
void push_front(Deque* q, int val) {
    DNode* node = (DNode*)malloc(sizeof(DNode));
    node->data = val;
    node->prev = NULL;
    node->next = q->front;
    if (q->front) q->front->prev = node;
    q->front = node;
    if (!q->rear) q->rear = node;
}
void push_back(Deque* q, int val) {
    DNode* node = (DNode*)malloc(sizeof(DNode));
    node->data = val;
    node->next = NULL;
    node->prev = q->rear;
    if (q->rear) q->rear->next = node;
    q->rear = node;
    if (!q->front) q->front = node;
}
int pop_front(Deque* q) {
    if (!q->front) return -1;
    DNode* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;
    if (q->front) q->front->prev = NULL;
    else q->rear = NULL;
    free(temp);
    return val;
}
int pop_back(Deque* q) {
    if (!q->rear) return -1;
    DNode* temp = q->rear;
    int val = temp->data;
    q->rear = q->rear->prev;
    if (q->rear) q->rear->next = NULL;
    else q->front = NULL;
    free(temp);
    return val;
}
void free_deque(Deque* q) {
    free_doubly(q->front);
    free(q);
}