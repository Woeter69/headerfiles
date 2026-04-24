#pragma once
#include <deque>

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
