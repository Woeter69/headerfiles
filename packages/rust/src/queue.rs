use std::collections::VecDeque;

pub struct Queue<T> {
    elements: VecDeque<T>,
}

impl<T> Queue<T> {
    pub fn new() -> Self {
        Queue { elements: VecDeque::new() }
    }

    pub fn enqueue(&mut self, item: T) {
        self.elements.push_back(item);
    }

    pub fn dequeue(&mut self) -> Option<T> {
        self.elements.pop_front()
    }
}

pub struct Deque<T> {
    elements: VecDeque<T>,
}

impl<T> Deque<T> {
    pub fn new() -> Self {
        Deque { elements: VecDeque::new() }
    }

    pub fn push_front(&mut self, item: T) {
        self.elements.push_front(item);
    }

    pub fn push_back(&mut self, item: T) {
        self.elements.push_back(item);
    }

    pub fn pop_front(&mut self) -> Option<T> {
        self.elements.pop_front()
    }

    pub fn pop_back(&mut self) -> Option<T> {
        self.elements.pop_back()
    }
}

pub struct CircularQueue<T> {
    elements: Vec<Option<T>>,
    head: usize,
    tail: usize,
    capacity: usize,
    size: usize,
}

impl<T> CircularQueue<T> {
    pub fn new(capacity: usize) -> Self {
        let mut elements = Vec::with_capacity(capacity);
        for _ in 0..capacity {
            elements.push(None);
        }
        CircularQueue {
            elements,
            head: 0,
            tail: 0,
            capacity,
            size: 0,
        }
    }

    pub fn enqueue(&mut self, item: T) -> bool {
        if self.is_full() {
            return false;
        }
        self.elements[self.tail] = Some(item);
        self.tail = (self.tail + 1) % self.capacity;
        self.size += 1;
        true
    }

    pub fn dequeue(&mut self) -> Option<T> {
        if self.is_empty() {
            return None;
        }
        let item = self.elements[self.head].take();
        self.head = (self.head + 1) % self.capacity;
        self.size -= 1;
        item
    }

    pub fn is_empty(&self) -> bool {
        self.size == 0
    }

    pub fn is_full(&self) -> bool {
        self.size == self.capacity
    }
}
