class Stack {
    constructor() {
        this.items = [];
    }
    push(element) {
        this.items.push(element);
    }
    pop() {
        if (this.items.length == 0) return "Underflow";
        return this.items.pop();
    }
    peek() {
        return this.items[this.items.length - 1];
    }
}

function isValidParentheses(s) {
    const stack = new Stack();
    const map = {
        ')': '(',
        '}': '{',
        ']': '['
    };
    for (let char of s) {
        if (char === '(' || char === '{' || char === '[') {
            stack.push(char);
        } else if (char === ')' || char === '}' || char === ']') {
            if (stack.items.length === 0 || stack.pop() !== map[char]) {
                return false;
            }
        }
    }
    return stack.items.length === 0;
}

module.exports = { Stack, isValidParentheses };
