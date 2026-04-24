#include "PriorityQueue.hpp"

PriorityQueue::PriorityQueue() : h(false) {} // Use max heap

void PriorityQueue::push(int val) {
    h.push(val);
}

void PriorityQueue::pop() {
    h.pop();
}

int PriorityQueue::top() const {
    return h.top();
}

bool PriorityQueue::isEmpty() const {
    return h.isEmpty();
}
