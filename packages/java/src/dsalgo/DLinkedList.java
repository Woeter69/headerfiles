package dsalgo;

public class DLinkedList<T> {
    private class Node {
        T data;
        Node next, prev;
        Node(T data) { this.data = data; this.next = null; this.prev = null; }
    }
    private Node head, tail;

    public void add(T data) {
        Node newNode = new Node(data);
        if (head == null) {
            head = tail = newNode;
        } else {
            tail.next = newNode;
            newNode.prev = tail;
            tail = newNode;
        }
    }

    public void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " <-> ");
            temp = temp.next;
        }
        System.out.println("null");
    }
}
