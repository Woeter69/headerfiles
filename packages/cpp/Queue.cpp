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

CircularQueue::CircularQueue(int k) : head(-1), tail(-1), size(0), capacity(k) {
    data.resize(k);
}

bool CircularQueue::enQueue(int value) {
    if (isFull()) return false;
    if (isEmpty()) head = 0;
    tail = (tail + 1) % capacity;
    data[tail] = value;
    size++;
    return true;
}

bool CircularQueue::deQueue() {
    if (isEmpty()) return false;
    if (head == tail) {
        head = -1;
        tail = -1;
    } else {
        head = (head + 1) % capacity;
    }
    size--;
    return true;
}

int CircularQueue::Front() const {
    return isEmpty() ? -1 : data[head];
}

int CircularQueue::Rear() const {
    return isEmpty() ? -1 : data[tail];
}

bool CircularQueue::isEmpty() const {
    return size == 0;
}

bool CircularQueue::isFull() const {
    return size == capacity;
}
