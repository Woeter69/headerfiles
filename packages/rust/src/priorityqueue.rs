use std::collections::BinaryHeap;
use std::cmp::Ordering;

#[derive(Eq, PartialEq)]
struct Node<T: Eq + PartialEq> {
    priority: i32,
    item: T,
}

impl<T: Eq + PartialEq> Ord for Node<T> {
    fn cmp(&self, other: &Self) -> Ordering {
        self.priority.cmp(&other.priority)
    }
}

impl<T: Eq + PartialEq> PartialOrd for Node<T> {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

pub struct PriorityQueue<T: Eq + PartialEq> {
    heap: BinaryHeap<Node<T>>,
}

impl<T: Eq + PartialEq> PriorityQueue<T> {
    pub fn new() -> Self {
        PriorityQueue { heap: BinaryHeap::new() }
    }

    pub fn push(&mut self, item: T, priority: i32) {
        self.heap.push(Node { priority, item });
    }

    pub fn pop(&mut self) -> Option<T> {
        self.heap.pop().map(|node| node.item)
    }
}
