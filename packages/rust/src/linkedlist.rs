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

    pub fn reverse(&mut self) {
        let mut prev = None;
        let mut curr = self.head.take();
        while let Some(mut node) = curr {
            let next = node.next.take();
            node.next = prev;
            prev = Some(node);
            curr = next;
        }
        self.head = prev;
    }

    pub fn has_cycle(&self) -> bool {
        let mut slow = &self.head;
        let mut fast = &self.head;

        while let Some(f_node) = fast {
            if let Some(f_next) = &f_node.next {
                fast = &f_next.next;
                if let Some(s_node) = slow {
                    slow = &s_node.next;
                }

                if let (Some(s), Some(f)) = (slow, fast) {
                    if std::ptr::eq(&**s, &**f) {
                        return true;
                    }
                }
            } else {
                break;
            }
        }
        false
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
