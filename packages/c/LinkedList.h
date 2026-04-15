#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct SNode {
    int data;
    struct SNode* next;
} SNode;

typedef struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
} DNode;

SNode* insert_singly(SNode* head, int val);
void print_singly(SNode* head);
void free_singly(SNode* head);

DNode* insert_doubly(DNode* head, int val);
void print_doubly(DNode* head);
void free_doubly(DNode* head);

#endif