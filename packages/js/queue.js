class Queue {
    constructor() {
        this.items = [];
    }
    enqueue(element) {
        this.items.push(element);
    }
    dequeue() {
        if (this.isEmpty()) return "Underflow";
        return this.items.shift();
    }
    isEmpty() {
        return this.items.length == 0;
    }
}

class Deque {
    constructor() {
        this.items = [];
    }
    addFront(element) {
        this.items.unshift(element);
    }
    addRear(element) {
        this.items.push(element);
    }
    removeFront() {
        if (this.isEmpty()) return "Underflow";
        return this.items.shift();
    }
    removeRear() {
        if (this.isEmpty()) return "Underflow";
        return this.items.pop();
    }
    isEmpty() {
        return this.items.length == 0;
    }
}

class CircularQueue {
    constructor(k) {
        this.items = new Array(k);
        this.maxSize = k;
        this.head = -1;
        this.tail = -1;
    }
    enqueue(element) {
        if (this.isFull()) return false;
        if (this.isEmpty()) {
            this.head = 0;
        }
        this.tail = (this.tail + 1) % this.maxSize;
        this.items[this.tail] = element;
        return true;
    }
    dequeue() {
        if (this.isEmpty()) return false;
        if (this.head === this.tail) {
            this.head = -1;
            this.tail = -1;
        } else {
            this.head = (this.head + 1) % this.maxSize;
        }
        return true;
    }
    Front() {
        if (this.isEmpty()) return -1;
        return this.items[this.head];
    }
    Rear() {
        if (this.isEmpty()) return -1;
        return this.items[this.tail];
    }
    isEmpty() {
        return this.head === -1;
    }
    isFull() {
        return (this.tail + 1) % this.maxSize === this.head;
    }
}

module.exports = { Queue, Deque, CircularQueue };
