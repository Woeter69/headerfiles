use std::cmp::Ord;

pub struct MinHeap<T: Ord> {
    elements: Vec<T>,
}

impl<T: Ord> MinHeap<T> {
    pub fn new() -> Self {
        MinHeap { elements: Vec::new() }
    }

    pub fn push(&mut self, item: T) {
        self.elements.push(item);
        self.heapify_up(self.elements.len() - 1);
    }

    fn heapify_up(&mut self, mut index: usize) {
        while index > 0 {
            let parent = (index - 1) / 2;
            if self.elements[index] < self.elements[parent] {
                self.elements.swap(index, parent);
                index = parent;
            } else {
                break;
            }
        }
    }
}

pub struct MaxHeap<T: Ord> {
    elements: Vec<T>,
}

impl<T: Ord> MaxHeap<T> {
    pub fn new() -> Self {
        MaxHeap { elements: Vec::new() }
    }

    pub fn push(&mut self, item: T) {
        self.elements.push(item);
        self.heapify_up(self.elements.len() - 1);
    }

    fn heapify_up(&mut self, mut index: usize) {
        while index > 0 {
            let parent = (index - 1) / 2;
            if self.elements[index] > self.elements[parent] {
                self.elements.swap(index, parent);
                index = parent;
            } else {
                break;
            }
        }
    }
}
