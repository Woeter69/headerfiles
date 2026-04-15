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
