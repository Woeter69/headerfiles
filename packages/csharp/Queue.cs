namespace csharp_packages;

public class MyQueue<T> {
    private readonly System.Collections.Generic.LinkedList<T> _items = new();
    public void Enqueue(T item) => _items.AddLast(item);
    public T Dequeue() {
        if (_items.Count == 0) throw new System.InvalidOperationException("Queue is empty");
        var item = _items.First!.Value;
        _items.RemoveFirst();
        return item;
    }
    public bool IsEmpty => _items.Count == 0;
}

public class MyDeque<T> {
    private readonly System.Collections.Generic.LinkedList<T> _items = new();
    public void AddFirst(T item) => _items.AddFirst(item);
    public void AddLast(T item) => _items.AddLast(item);
    public T RemoveFirst() {
        if (_items.Count == 0) throw new System.InvalidOperationException("Deque is empty");
        var item = _items.First!.Value;
        _items.RemoveFirst();
        return item;
    }
    public T RemoveLast() {
        if (_items.Count == 0) throw new System.InvalidOperationException("Deque is empty");
        var item = _items.Last!.Value;
        _items.RemoveLast();
        return item;
    }
    public bool IsEmpty => _items.Count == 0;
}