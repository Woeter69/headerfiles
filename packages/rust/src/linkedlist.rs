use std::rc::Rc;
use std::cell::RefCell;

pub struct SinglyLinkedList<T> {
    head: Option<Box<SinglyNode<T>>>,
}

struct SinglyNode<T> {
    data: T,
    next: Option<Box<SinglyNode<T>>>,
}

impl<T> SinglyLinkedList<T> {
    pub fn new() -> Self {
        SinglyLinkedList { head: None }
    }

    pub fn push_front(&mut self, data: T) {
        let new_node = Box::new(SinglyNode {
            data,
            next: self.head.take(),
        });
        self.head = Some(new_node);
    }
}

pub struct DoublyLinkedList<T> {
    head: Option<Rc<RefCell<DoublyNode<T>>>>,
    tail: Option<Rc<RefCell<DoublyNode<T>>>>,
}

struct DoublyNode<T> {
    data: T,
    prev: Option<Rc<RefCell<DoublyNode<T>>>>,
    next: Option<Rc<RefCell<DoublyNode<T>>>>,
}

impl<T> DoublyLinkedList<T> {
    pub fn new() -> Self {
        DoublyLinkedList { head: None, tail: None }
    }

    pub fn push_back(&mut self, data: T) {
        let new_node = Rc::new(RefCell::new(DoublyNode {
            data,
            prev: self.tail.clone(),
            next: None,
        }));

        if let Some(tail) = self.tail.take() {
            tail.borrow_mut().next = Some(new_node.clone());
        } else {
            self.head = Some(new_node.clone());
        }
        self.tail = Some(new_node);
    }
}
