#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

SNode* insert_singly(SNode* head, int val) {
    SNode* node = (SNode*)malloc(sizeof(SNode));
    node->data = val;
    node->next = head;
    return node;
}
void print_singly(SNode* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void free_singly(SNode* head) {
    while (head) {
        SNode* temp = head;
        head = head->next;
        free(temp);
    }
}

DNode* insert_doubly(DNode* head, int val) {
    DNode* node = (DNode*)malloc(sizeof(DNode));
    node->data = val;
    node->next = head;
    node->prev = NULL;
    if (head) {
        head->prev = node;
    }
    return node;
}
void print_doubly(DNode* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void free_doubly(DNode* head) {
    while (head) {
        DNode* temp = head;
        head = head->next;
        free(temp);
    }
}