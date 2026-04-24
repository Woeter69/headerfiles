#ifndef HEAP_H
#define HEAP_H

typedef struct Heap {
    int* data;
    int size;
    int capacity;
    int is_min;
} Heap;

Heap* create_heap(int capacity, int is_min);
void insert_heap(Heap* h, int val);
int extract_heap(Heap* h);
void free_heap(Heap* h);

#endif