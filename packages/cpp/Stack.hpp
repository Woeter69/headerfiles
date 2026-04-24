#pragma once
#include <vector>

class Stack {
    std::vector<int> data;
public:
    void push(int val);
    void pop();
    int top() const;
    bool isEmpty() const;
};
