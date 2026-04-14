namespace csharp_packages;
using System;

public class MyPriorityQueue<T> where T : IComparable<T> {
    private readonly MinHeap<T> _heap = new();
    public void Enqueue(T item) => _heap.Insert(item);
    public T Dequeue() => _heap.ExtractMin();
    public bool IsEmpty => _heap.IsEmpty;
}