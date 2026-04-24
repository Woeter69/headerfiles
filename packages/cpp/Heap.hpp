#pragma once
#include <vector>

class Heap {
    std::vector<int> data;
    bool isMin;
    void heapifyUp(int index);
    void heapifyDown(int index);
public:
    Heap(bool isMinHeap = true);
    void push(int val);
    void pop();
    int top() const;
    bool isEmpty() const;
};
