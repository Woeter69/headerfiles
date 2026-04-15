#include "Stack.h"
#include <stdlib.h>
Stack* create_stack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}
void push(Stack* s, int val) {
    s->top = insert_singly(s->top, val);
}
int pop(Stack* s) {
    if (!s->top) return -1;
    SNode* temp = s->top;
    int val = temp->data;
    s->top = s->top->next;
    free(temp);
    return val;
}
int is_empty_stack(Stack* s) {
    return s->top == NULL;
}
void free_stack(Stack* s) {
    free_singly(s->top);
    free(s);
}