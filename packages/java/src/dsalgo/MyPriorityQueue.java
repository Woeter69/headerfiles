package dsalgo;

public class MyPriorityQueue<T extends Comparable<T>> {
    private MyHeap<T> heap;

    public MyPriorityQueue() {
        this.heap = new MyHeap<>(true); // Default to min-heap based priority queue
    }

    public void enqueue(T item) {
        heap.insert(item);
    }

    public T dequeue() {
        return heap.extractTop();
    }

    public boolean isEmpty() {
        return heap.isEmpty();
    }
}
