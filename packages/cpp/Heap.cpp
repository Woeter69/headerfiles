#include "Heap.hpp"
#include <algorithm>

Heap::Heap(bool isMinHeap) : isMin(isMinHeap) {}

void Heap::heapifyUp(int index) {
    while (index > 0) {
        int p = (index - 1) / 2;
        if ((isMin && data[index] < data[p]) || (!isMin && data[index] > data[p])) {
            std::swap(data[index], data[p]);
            index = p;
        } else {
            break;
        }
    }
}

void Heap::heapifyDown(int index) {
    int n = data.size();
    while (true) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int extremum = index;

        if (left < n && ((isMin && data[left] < data[extremum]) || (!isMin && data[left] > data[extremum]))) {
            extremum = left;
        }
        if (right < n && ((isMin && data[right] < data[extremum]) || (!isMin && data[right] > data[extremum]))) {
            extremum = right;
        }

        if (extremum != index) {
            std::swap(data[index], data[extremum]);
            index = extremum;
        } else {
            break;
        }
    }
}

void Heap::push(int val) {
    data.push_back(val);
    heapifyUp(data.size() - 1);
}

void Heap::pop() {
    if (data.empty()) return;
    data[0] = data.back();
    data.pop_back();
    if (!data.empty()) {
        heapifyDown(0);
    }
}

int Heap::top() const {
    return data.empty() ? -1 : data[0];
}

bool Heap::isEmpty() const {
    return data.empty();
}
