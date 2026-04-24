package dsalgo;

public class SLinkedList<T> {
    private class Node {
        T data;
        Node next;
        Node(T data) { this.data = data; this.next = null; }
    }
    private Node head;

    public void add(T data) {
        if (head == null) {
            head = new Node(data);
        } else {
            Node temp = head;
            while (temp.next != null) {
                temp = temp.next;
            }
            temp.next = new Node(data);
        }
    }

    public void printList() {
        Node temp = head;
        while (temp != null) {
            System.out.print(temp.data + " -> ");
            temp = temp.next;
        }
        System.out.println("null");
    }
}
