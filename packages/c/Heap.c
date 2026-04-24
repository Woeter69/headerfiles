#include "Heap.h"
#include <stdlib.h>

Heap* create_heap(int capacity, int is_min) {
    Heap* h = (Heap*)malloc(sizeof(Heap));
    h->data = (int*)malloc(sizeof(int) * capacity);
    h->size = 0;
    h->capacity = capacity;
    h->is_min = is_min;
    return h;
}
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}
void heapify_up(Heap* h, int idx) {
    if (idx == 0) return;
    int p = (idx - 1) / 2;
    if ((h->is_min && h->data[idx] < h->data[p]) || (!h->is_min && h->data[idx] > h->data[p])) {
        swap(&h->data[idx], &h->data[p]);
        heapify_up(h, p);
    }
}
void insert_heap(Heap* h, int val) {
    if (h->size == h->capacity) return;
    h->data[h->size] = val;
    heapify_up(h, h->size);
    h->size++;
}
void heapify_down(Heap* h, int idx) {
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;
    int best = idx;
    if (l < h->size && ((h->is_min && h->data[l] < h->data[best]) || (!h->is_min && h->data[l] > h->data[best]))) {
        best = l;
    }
    if (r < h->size && ((h->is_min && h->data[r] < h->data[best]) || (!h->is_min && h->data[r] > h->data[best]))) {
        best = r;
    }
    if (best != idx) {
        swap(&h->data[idx], &h->data[best]);
        heapify_down(h, best);
    }
}
int extract_heap(Heap* h) {
    if (h->size == 0) return -1;
    int val = h->data[0];
    h->data[0] = h->data[h->size - 1];
    h->size--;
    heapify_down(h, 0);
    return val;
}
void free_heap(Heap* h) {
    free(h->data);
    free(h);
}