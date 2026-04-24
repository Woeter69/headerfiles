class PriorityQueue {
    constructor() {
        this.items = [];
    }
    enqueue(element, priority) {
        let qElement = { element, priority };
        let contain = false;

        for (let i = 0; i < this.items.length; i++) {
            if (this.items[i].priority > qElement.priority) {
                this.items.splice(i, 0, qElement);
                contain = true;
                break;
            }
        }

        if (!contain) {
            this.items.push(qElement);
        }
    }
    dequeue() {
        if (this.items.length === 0) return "Underflow";
        return this.items.shift();
    }
}

module.exports = { PriorityQueue };
