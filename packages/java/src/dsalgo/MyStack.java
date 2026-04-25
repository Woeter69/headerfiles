package dsalgo;

import java.util.EmptyStackException;

public class MyStack<T> {
    private class Node {
        T data;
        Node next;
        Node(T data) { this.data = data; }
    }
    private Node top;

    public void push(T data) {
        Node newNode = new Node(data);
        newNode.next = top;
        top = newNode;
    }

    public T pop() {
        if (top == null) throw new EmptyStackException();
        T data = top.data;
        top = top.next;
        return data;
    }

    public boolean isEmpty() {
        return top == null;
    }

    public static boolean isValidParentheses(String s) {
        MyStack<Character> stack = new MyStack<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) return false;
                char top = stack.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }
}
