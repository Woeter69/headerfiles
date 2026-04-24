namespace csharp_packages;
using System.Collections.Generic;
using System;

public class MinHeap<T> where T : IComparable<T> {
    private readonly List<T> _elements = new();
    public void Insert(T item) {
        _elements.Add(item);
        HeapifyUp(_elements.Count - 1);
    }
    public T ExtractMin() {
        if (_elements.Count == 0) throw new InvalidOperationException("Heap is empty");
        var min = _elements[0];
        _elements[0] = _elements[^1];
        _elements.RemoveAt(_elements.Count - 1);
        HeapifyDown(0);
        return min;
    }
    private void HeapifyUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (_elements[i].CompareTo(_elements[p]) >= 0) break;
            (_elements[i], _elements[p]) = (_elements[p], _elements[i]);
            i = p;
        }
    }
    private void HeapifyDown(int i) {
        while (true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int smallest = i;
            if (l < _elements.Count && _elements[l].CompareTo(_elements[smallest]) < 0) smallest = l;
            if (r < _elements.Count && _elements[r].CompareTo(_elements[smallest]) < 0) smallest = r;
            if (smallest == i) break;
            (_elements[i], _elements[smallest]) = (_elements[smallest], _elements[i]);
            i = smallest;
        }
    }
    public bool IsEmpty => _elements.Count == 0;
}

public class MaxHeap<T> where T : IComparable<T> {
    private readonly List<T> _elements = new();
    public void Insert(T item) {
        _elements.Add(item);
        HeapifyUp(_elements.Count - 1);
    }
    public T ExtractMax() {
        if (_elements.Count == 0) throw new InvalidOperationException("Heap is empty");
        var max = _elements[0];
        _elements[0] = _elements[^1];
        _elements.RemoveAt(_elements.Count - 1);
        HeapifyDown(0);
        return max;
    }
    private void HeapifyUp(int i) {
        while (i > 0) {
            int p = (i - 1) / 2;
            if (_elements[i].CompareTo(_elements[p]) <= 0) break;
            (_elements[i], _elements[p]) = (_elements[p], _elements[i]);
            i = p;
        }
    }
    private void HeapifyDown(int i) {
        while (true) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int largest = i;
            if (l < _elements.Count && _elements[l].CompareTo(_elements[largest]) > 0) largest = l;
            if (r < _elements.Count && _elements[r].CompareTo(_elements[largest]) > 0) largest = r;
            if (largest == i) break;
            (_elements[i], _elements[largest]) = (_elements[largest], _elements[i]);
            i = largest;
        }
    }
    public bool IsEmpty => _elements.Count == 0;
}