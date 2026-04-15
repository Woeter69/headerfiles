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
