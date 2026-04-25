#pragma once
#include <deque>
#include <vector>

class Queue {
    std::deque<int> data;
public:
    void push(int val);
    void pop();
    int front() const;
    bool isEmpty() const;
};

class Deque {
    std::deque<int> data;
public:
    void push_front(int val);
    void push_back(int val);
    void pop_front();
    void pop_back();
    int front() const;
    int back() const;
    bool isEmpty() const;
};

class CircularQueue {
    std::vector<int> data;
    int head;
    int tail;
    int size;
    int capacity;
public:
    CircularQueue(int k);
    bool enQueue(int value);
    bool deQueue();
    int Front() const;
    int Rear() const;
    bool isEmpty() const;
    bool isFull() const;
};
