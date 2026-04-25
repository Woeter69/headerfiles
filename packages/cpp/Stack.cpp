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

bool isValidParentheses(const std::string& s) {
    Stack st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.isEmpty()) return false;
            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    return st.isEmpty();
}
