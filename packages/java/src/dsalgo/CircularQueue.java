package dsalgo;

public class CircularQueue<T> {
    private Object[] queue;
    private int front;
    private int rear;
    private int size;
    private int capacity;

    public CircularQueue(int k) {
        capacity = k;
        queue = new Object[k];
        front = 0;
        rear = -1;
        size = 0;
    }

    public boolean enqueue(T value) {
        if (isFull()) {
            return false;
        }
        rear = (rear + 1) % capacity;
        queue[rear] = value;
        size++;
        return true;
    }

    @SuppressWarnings("unchecked")
    public T dequeue() {
        if (isEmpty()) {
            return null;
        }
        T value = (T) queue[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    @SuppressWarnings("unchecked")
    public T Front() {
        if (isEmpty()) return null;
        return (T) queue[front];
    }

    @SuppressWarnings("unchecked")
    public T Rear() {
        if (isEmpty()) return null;
        return (T) queue[rear];
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == capacity;
    }
}
