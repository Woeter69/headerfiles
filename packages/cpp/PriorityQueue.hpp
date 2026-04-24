#pragma once
#include "Heap.hpp"

class PriorityQueue {
    Heap h;
public:
    PriorityQueue();
    void push(int val);
    void pop();
    int top() const;
    bool isEmpty() const;
};
