package dsalgo;

import java.util.ArrayList;

public class MyHeap<T extends Comparable<T>> {
    private ArrayList<T> heap;
    private boolean isMinHeap;

    public MyHeap(boolean isMinHeap) {
        this.heap = new ArrayList<>();
        this.isMinHeap = isMinHeap;
    }

    private int parent(int i) { return (i - 1) / 2; }
    private int left(int i) { return 2 * i + 1; }
    private int right(int i) { return 2 * i + 2; }

    private void swap(int i, int j) {
        T temp = heap.get(i);
        heap.set(i, heap.get(j));
        heap.set(j, temp);
    }

    private boolean compare(T a, T b) {
        if (isMinHeap) {
            return a.compareTo(b) < 0;
        } else {
            return a.compareTo(b) > 0;
        }
    }

    public void insert(T key) {
        heap.add(key);
        int i = heap.size() - 1;
        while (i != 0 && compare(heap.get(i), heap.get(parent(i)))) {
            swap(i, parent(i));
            i = parent(i);
        }
    }

    public void heapify(int i) {
        int l = left(i);
        int r = right(i);
        int extremum = i;

        if (l < heap.size() && compare(heap.get(l), heap.get(i)))
            extremum = l;
        if (r < heap.size() && compare(heap.get(r), heap.get(extremum)))
            extremum = r;

        if (extremum != i) {
            swap(i, extremum);
            heapify(extremum);
        }
    }

    public T extractTop() {
        if (heap.size() <= 0) return null;
        if (heap.size() == 1) return heap.remove(0);

        T root = heap.get(0);
        heap.set(0, heap.remove(heap.size() - 1));
        heapify(0);

        return root;
    }

    public T peek() {
        if (heap.size() == 0) return null;
        return heap.get(0);
    }

    public boolean isEmpty() {
        return heap.isEmpty();
    }
}
