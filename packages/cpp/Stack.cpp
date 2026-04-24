#include "Stack.hpp"

void Stack::push(int val) {
    data.push_back(val);
}

void Stack::pop() {
    if (!data.empty()) {
        data.pop_back();
    }
}

int Stack::top() const {
    return data.empty() ? -1 : data.back();
}

bool Stack::isEmpty() const {
    return data.empty();
}
