package dsalgo;

import java.util.NoSuchElementException;

public class MyQueue<T> {
    private class Node {
        T data;
        Node next;
        Node(T data) { this.data = data; }
    }
    private Node head, tail;

    public void enqueue(T data) {
        Node newNode = new Node(data);
        if (tail != null) {
            tail.next = newNode;
        }
        tail = newNode;
        if (head == null) {
            head = newNode;
        }
    }

    public T dequeue() {
        if (head == null) throw new NoSuchElementException();
        T data = head.data;
        head = head.next;
        if (head == null) {
            tail = null;
        }
        return data;
    }
    
    public boolean isEmpty() {
        return head == null;
    }
}
