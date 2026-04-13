package tree

import "errors"

// Node represents a single node in a Binary Tree.
// It contains a generic Value and pointers to its Left and Right child nodes.
type Node[T any] struct {
	Value       T        // The data stored in the node.
	Left, Right *Node[T] // Pointers to the left and right children.
}

// BST represents a generic Binary Search Tree (BST).
// It maintains an ordered structure where the left child is less than the parent,
// and the right child is greater than or equal to the parent.
type BST[T any] struct {
	Root *Node[T]          // Pointer to the root node of the tree.
	Less func(a, b T) bool // Comparator function defining the ordering.
}

// NewBST creates and returns a new, empty Binary Search Tree.
// The caller must provide a 'less' function that defines the sorting logic.
func NewBST[T any](less func(a, b T) bool) *BST[T] {
	return &BST[T]{Less: less}
}

// Insert adds a new value into the Binary Search Tree while maintaining the BST property.
// Time Complexity: O(log n) average case, O(n) worst case (unbalanced tree).
func (t *BST[T]) Insert(value T) {
	t.Root = t.insert(t.Root, value)
}

// insert is a recursive helper function for Insert.
func (t *BST[T]) insert(node *Node[T], value T) *Node[T] {
	if node == nil {
		return &Node[T]{Value: value}
	}
	// Decide whether to traverse left or right based on the comparator.
	if t.Less(value, node.Value) {
		node.Left = t.insert(node.Left, value)
	} else {
		node.Right = t.insert(node.Right, value)
	}
	return node
}

// Search determines whether a given value exists within the Binary Search Tree.
// Time Complexity: O(log n) average case, O(n) worst case.
func (t *BST[T]) Search(value T) bool {
	return t.search(t.Root, value)
}

// search is a recursive helper function for Search.
func (t *BST[T]) search(node *Node[T], value T) bool {
	if node == nil {
		return false
	}
	// Check if values are equal (neither is less than the other)
	if !t.Less(value, node.Value) && !t.Less(node.Value, value) {
		return true
	}
	// Recursively search left or right subtree
	if t.Less(value, node.Value) {
		return t.search(node.Left, value)
	}
	return t.search(node.Right, value)
}

// GeneralNode represents a node in a General (N-ary) Tree.
// Unlike a binary tree, it can have any number of child nodes.
type GeneralNode[T comparable] struct {
	Value    T                  // The data stored in the node.
	Children []*GeneralNode[T]  // A slice of pointers to all child nodes.
}

// GeneralTree represents a generic tree structure without node degree limits.
type GeneralTree[T comparable] struct {
	Root *GeneralNode[T] // Pointer to the root node.
}

// NewGeneralTree creates and returns a new GeneralTree, initializing its root node.
func NewGeneralTree[T comparable](rootValue T) *GeneralTree[T] {
	return &GeneralTree[T]{
		Root: &GeneralNode[T]{Value: rootValue},
	}
}

// AddEdge attaches a new child node to an existing parent node.
// It searches the entire tree for the parent by value and appends the child.
// Returns an error if the parent node cannot be found.
// Time Complexity: O(n) where n is the number of nodes (due to search).
func (t *GeneralTree[T]) AddEdge(parentValue, childValue T) error {
	parent := t.Find(t.Root, parentValue)
	if parent == nil {
		return errors.New("parent node not found")
	}
	parent.Children = append(parent.Children, &GeneralNode[T]{Value: childValue})
	return nil
}

// Find recursively searches the general tree for a node containing the target value.
// It returns a pointer to the node if found, or nil if not.
// Time Complexity: O(n) where n is the total number of nodes.
func (t *GeneralTree[T]) Find(node *GeneralNode[T], value T) *GeneralNode[T] {
	if node == nil {
		return nil
	}
	if node.Value == value {
		return node
	}
	for _, child := range node.Children {
		if found := t.Find(child, value); found != nil {
			return found
		}
	}
	return nil
}

// TraverseBFS executes a Breadth-First Search (Level-Order Traversal) across the general tree.
// It invokes the provided 'visit' function for every node value it encounters.
// Time Complexity: O(n)
func (t *GeneralTree[T]) TraverseBFS(visit func(T)) {
	if t.Root == nil {
		return
	}
	queue := []*GeneralNode[T]{t.Root}
	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:]
		visit(curr.Value)
		queue = append(queue, curr.Children...)
	}
}
