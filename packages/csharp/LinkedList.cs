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
    
    public void Reverse() {
        SinglyLinkedListNode<T>? prev = null;
        SinglyLinkedListNode<T>? current = Head;
        SinglyLinkedListNode<T>? next = null;
        while (current != null) {
            next = current.Next;
            current.Next = prev;
            prev = current;
            current = next;
        }
        Head = prev;
    }
    
    public bool HasCycle() {
        if (Head == null) return false;
        SinglyLinkedListNode<T>? slow = Head;
        SinglyLinkedListNode<T>? fast = Head;
        while (fast != null && fast.Next != null) {
            slow = slow!.Next;
            fast = fast.Next.Next;
            if (ReferenceEquals(slow, fast)) return true;
        }
        return false;
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