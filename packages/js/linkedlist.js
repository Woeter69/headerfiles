class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
}

class SinglyLinkedList {
    constructor() {
        this.head = null;
    }
    append(data) {
        if (!this.head) {
            this.head = new Node(data);
            return;
        }
        let current = this.head;
        while (current.next) {
            current = current.next;
        }
        current.next = new Node(data);
    }
}

class DNode {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
    }
    append(data) {
        const newNode = new DNode(data);
        if (!this.head) {
            this.head = newNode;
            this.tail = newNode;
            return;
        }
        this.tail.next = newNode;
        newNode.prev = this.tail;
        this.tail = newNode;
    }
}

module.exports = { SinglyLinkedList, DoublyLinkedList };
