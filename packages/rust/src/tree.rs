pub struct BSTNode<T: Ord> {
    pub value: T,
    pub left: Option<Box<BSTNode<T>>>,
    pub right: Option<Box<BSTNode<T>>>,
}

pub struct BST<T: Ord> {
    pub root: Option<Box<BSTNode<T>>>,
}

impl<T: Ord> BST<T> {
    pub fn new() -> Self {
        BST { root: None }
    }

    pub fn insert(&mut self, value: T) {
        let new_node = Box::new(BSTNode { value, left: None, right: None });
        if let Some(ref mut root) = self.root {
            Self::insert_node(root, new_node);
        } else {
            self.root = Some(new_node);
        }
    }

    fn insert_node(node: &mut Box<BSTNode<T>>, new_node: Box<BSTNode<T>>) {
        if new_node.value < node.value {
            if let Some(ref mut left) = node.left {
                Self::insert_node(left, new_node);
            } else {
                node.left = Some(new_node);
            }
        } else {
            if let Some(ref mut right) = node.right {
                Self::insert_node(right, new_node);
            } else {
                node.right = Some(new_node);
            }
        }
    }
}

pub struct NaryNode<T> {
    pub value: T,
    pub children: Vec<Box<NaryNode<T>>>,
}

pub struct NaryTree<T> {
    pub root: Option<Box<NaryNode<T>>>,
}

impl<T> NaryTree<T> {
    pub fn new() -> Self {
        NaryTree { root: None }
    }
}

use std::collections::HashMap;
use std::cmp::max;

#[derive(Default)]
pub struct TrieNode {
    pub children: HashMap<char, TrieNode>,
    pub is_end_of_word: bool,
}

#[derive(Default)]
pub struct Trie {
    pub root: TrieNode,
}

impl Trie {
    pub fn new() -> Self {
        Trie { root: TrieNode::default() }
    }

    pub fn insert(&mut self, word: &str) {
        let mut node = &mut self.root;
        for c in word.chars() {
            node = node.children.entry(c).or_default();
        }
        node.is_end_of_word = true;
    }

    pub fn search(&self, word: &str) -> bool {
        let mut node = &self.root;
        for c in word.chars() {
            if let Some(child) = node.children.get(&c) {
                node = child;
            } else {
                return false;
            }
        }
        node.is_end_of_word
    }

    pub fn starts_with(&self, prefix: &str) -> bool {
        let mut node = &self.root;
        for c in prefix.chars() {
            if let Some(child) = node.children.get(&c) {
                node = child;
            } else {
                return false;
            }
        }
        true
    }
}

pub struct AVLNode<T: Ord> {
    pub value: T,
    pub height: i32,
    pub left: Option<Box<AVLNode<T>>>,
    pub right: Option<Box<AVLNode<T>>>,
}

pub struct AVLTree<T: Ord> {
    pub root: Option<Box<AVLNode<T>>>,
}

impl<T: Ord> AVLTree<T> {
    pub fn new() -> Self {
        AVLTree { root: None }
    }

    fn height(node: &Option<Box<AVLNode<T>>>) -> i32 {
        node.as_ref().map_or(0, |n| n.height)
    }

    fn update_height(node: &mut Box<AVLNode<T>>) {
        node.height = 1 + max(Self::height(&node.left), Self::height(&node.right));
    }

    fn rotate_right(mut y: Box<AVLNode<T>>) -> Box<AVLNode<T>> {
        let mut x = y.left.unwrap();
        let t2 = x.right.take();
        y.left = t2;
        Self::update_height(&mut y);
        x.right = Some(y);
        Self::update_height(&mut x);
        x
    }

    fn rotate_left(mut x: Box<AVLNode<T>>) -> Box<AVLNode<T>> {
        let mut y = x.right.unwrap();
        let t2 = y.left.take();
        x.right = t2;
        Self::update_height(&mut x);
        y.left = Some(x);
        Self::update_height(&mut y);
        y
    }

    pub fn insert(&mut self, value: T) {
        let root = self.root.take();
        self.root = Some(Self::insert_node(root, value));
    }

    fn insert_node(node: Option<Box<AVLNode<T>>>, value: T) -> Box<AVLNode<T>> {
        let mut node = match node {
            Some(mut n) => {
                if value < n.value {
                    n.left = Some(Self::insert_node(n.left.take(), value));
                } else if value > n.value {
                    n.right = Some(Self::insert_node(n.right.take(), value));
                } else {
                    return n;
                }
                n
            }
            None => {
                return Box::new(AVLNode {
                    value,
                    height: 1,
                    left: None,
                    right: None,
                });
            }
        };

        Self::update_height(&mut node);
        let balance = Self::height(&node.left) - Self::height(&node.right);

        if balance > 1 {
            let left_balance = node.left.as_ref().map_or(0, |n| Self::height(&n.left) - Self::height(&n.right));
            if left_balance < 0 {
                node.left = Some(Self::rotate_left(node.left.unwrap()));
            }
            return Self::rotate_right(node);
        }

        if balance < -1 {
            let right_balance = node.right.as_ref().map_or(0, |n| Self::height(&n.left) - Self::height(&n.right));
            if right_balance > 0 {
                node.right = Some(Self::rotate_right(node.right.unwrap()));
            }
            return Self::rotate_left(node);
        }

        node
    }
}
