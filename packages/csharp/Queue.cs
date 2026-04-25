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

public class CircularQueue<T> {
    private readonly T[] _items;
    private int _front, _rear, _count, _capacity;
    
    public CircularQueue(int capacity) {
        _capacity = capacity;
        _items = new T[capacity];
        _front = 0;
        _rear = -1;
        _count = 0;
    }
    
    public bool Enqueue(T item) {
        if (IsFull) return false;
        _rear = (_rear + 1) % _capacity;
        _items[_rear] = item;
        _count++;
        return true;
    }
    
    public T Dequeue() {
        if (IsEmpty) throw new System.InvalidOperationException("Queue is empty");
        T item = _items[_front];
        _front = (_front + 1) % _capacity;
        _count--;
        return item;
    }
    
    public bool IsEmpty => _count == 0;
    public bool IsFull => _count == _capacity;
}