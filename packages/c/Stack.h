#ifndef STACK_H
#define STACK_H
#include "LinkedList.h"
typedef struct Stack {
    SNode* top;
} Stack;

Stack* create_stack();
void push(Stack* s, int val);
int pop(Stack* s);
int is_empty_stack(Stack* s);
void free_stack(Stack* s);
int is_valid_parentheses(const char* s);
#endif