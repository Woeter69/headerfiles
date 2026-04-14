namespace csharp_packages;

public class SinglyLinkedListNode<T> {
    public T Data;
    public SinglyLinkedListNode<T>? Next;
    public SinglyLinkedListNode(T data) { Data = data; }
}

public class SinglyLinkedList<T> {
    public SinglyLinkedListNode<T>? Head;
    public void Add(T data) {
        if (Head == null) { Head = new SinglyLinkedListNode<T>(data); return; }
        var curr = Head;
        while (curr.Next != null) curr = curr.Next;
        curr.Next = new SinglyLinkedListNode<T>(data);
    }
}

public class DoublyLinkedListNode<T> {
    public T Data;
    public DoublyLinkedListNode<T>? Next;
    public DoublyLinkedListNode<T>? Prev;
    public DoublyLinkedListNode(T data) { Data = data; }
}

public class DoublyLinkedList<T> {
    public DoublyLinkedListNode<T>? Head;
    public void Add(T data) {
        if (Head == null) { Head = new DoublyLinkedListNode<T>(data); return; }
        var curr = Head;
        while (curr.Next != null) curr = curr.Next;
        var node = new DoublyLinkedListNode<T>(data);
        curr.Next = node;
        node.Prev = curr;
    }
}