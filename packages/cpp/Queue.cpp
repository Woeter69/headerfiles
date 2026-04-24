#include "Queue.hpp"

// Queue
void Queue::push(int val) {
    data.push_back(val);
}

void Queue::pop() {
    if (!data.empty()) {
        data.pop_front();
    }
}

int Queue::front() const {
    return data.empty() ? -1 : data.front();
}

bool Queue::isEmpty() const {
    return data.empty();
}

// Deque
void Deque::push_front(int val) {
    data.push_front(val);
}

void Deque::push_back(int val) {
    data.push_back(val);
}

void Deque::pop_front() {
    if (!data.empty()) {
        data.pop_front();
    }
}

void Deque::pop_back() {
    if (!data.empty()) {
        data.pop_back();
    }
}

int Deque::front() const {
    return data.empty() ? -1 : data.front();
}

int Deque::back() const {
    return data.empty() ? -1 : data.back();
}

bool Deque::isEmpty() const {
    return data.empty();
}
