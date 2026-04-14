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

module.exports = { Queue, Deque };
