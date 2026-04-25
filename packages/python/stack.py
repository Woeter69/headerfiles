class Stack:
    def __init__(self):
        self.items = []
        
    def push(self, item):
        self.items.append(item)
        
    def pop(self):
        if not self.is_empty():
            return self.items.pop()
        return None
        
    def is_empty(self):
        return len(self.items) == 0
        
    def peek(self):
        if not self.is_empty():
            return self.items[-1]
        return None

def is_valid_parentheses(s):
    stack = Stack()
    mapping = {")": "(", "}": "{", "]": "["}
    for char in s:
        if char in mapping:
            top_element = stack.pop() if not stack.is_empty() else '#'
            if mapping[char] != top_element:
                return False
        else:
            stack.push(char)
    return stack.is_empty()
