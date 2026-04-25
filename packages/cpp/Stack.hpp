#pragma once
#include <vector>
#include <string>

class Stack {
    std::vector<int> data;
public:
    void push(int val);
    void pop();
    int top() const;
    bool isEmpty() const;
};

bool isValidParentheses(const std::string& s);
