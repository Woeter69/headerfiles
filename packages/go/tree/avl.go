package tree

// AVLNode represents a node in an AVL Tree.
type AVLNode[T any] struct {
	Value       T
	Height      int
	Left, Right *AVLNode[T]
}

// AVLTree represents a generic AVL Tree.
type AVLTree[T any] struct {
	Root *AVLNode[T]
	Less func(a, b T) bool
}

// NewAVLTree creates and returns a new, empty AVL Tree.
func NewAVLTree[T any](less func(a, b T) bool) *AVLTree[T] {
	return &AVLTree[T]{Less: less}
}

// height returns the height of the node.
func (t *AVLTree[T]) height(node *AVLNode[T]) int {
	if node == nil {
		return 0
	}
	return node.Height
}

// maxInt returns the maximum of two integers.
func maxInt(a, b int) int {
	if a > b {
		return a
	}
	return b
}

// updateHeight updates the height of a node.
func (t *AVLTree[T]) updateHeight(node *AVLNode[T]) {
	if node != nil {
		node.Height = 1 + maxInt(t.height(node.Left), t.height(node.Right))
	}
}

// getBalance returns the balance factor of the node.
func (t *AVLTree[T]) getBalance(node *AVLNode[T]) int {
	if node == nil {
		return 0
	}
	return t.height(node.Left) - t.height(node.Right)
}

// rightRotate performs a right rotation.
func (t *AVLTree[T]) rightRotate(y *AVLNode[T]) *AVLNode[T] {
	x := y.Left
	T2 := x.Right

	x.Right = y
	y.Left = T2

	t.updateHeight(y)
	t.updateHeight(x)

	return x
}

// leftRotate performs a left rotation.
func (t *AVLTree[T]) leftRotate(x *AVLNode[T]) *AVLNode[T] {
	y := x.Right
	T2 := y.Left

	y.Left = x
	x.Right = T2

	t.updateHeight(x)
	t.updateHeight(y)

	return y
}

// Insert adds a value to the AVL Tree.
func (t *AVLTree[T]) Insert(value T) {
	t.Root = t.insert(t.Root, value)
}

func (t *AVLTree[T]) insert(node *AVLNode[T], value T) *AVLNode[T] {
	if node == nil {
		return &AVLNode[T]{Value: value, Height: 1}
	}

	if t.Less(value, node.Value) {
		node.Left = t.insert(node.Left, value)
	} else if t.Less(node.Value, value) {
		node.Right = t.insert(node.Right, value)
	} else {
		// Duplicate values are not allowed in this simple AVL tree.
		return node
	}

	t.updateHeight(node)
	balance := t.getBalance(node)

	// Left Left Case
	if balance > 1 && t.Less(value, node.Left.Value) {
		return t.rightRotate(node)
	}

	// Right Right Case
	if balance < -1 && t.Less(node.Right.Value, value) {
		return t.leftRotate(node)
	}

	// Left Right Case
	if balance > 1 && t.Less(node.Left.Value, value) {
		node.Left = t.leftRotate(node.Left)
		return t.rightRotate(node)
	}

	// Right Left Case
	if balance < -1 && t.Less(value, node.Right.Value) {
		node.Right = t.rightRotate(node.Right)
		return t.leftRotate(node)
	}

	return node
}

// Search determines whether a given value exists within the AVL Tree.
func (t *AVLTree[T]) Search(value T) bool {
	return t.search(t.Root, value)
}

func (t *AVLTree[T]) search(node *AVLNode[T], value T) bool {
	if node == nil {
		return false
	}
	if !t.Less(value, node.Value) && !t.Less(node.Value, value) {
		return true
	}
	if t.Less(value, node.Value) {
		return t.search(node.Left, value)
	}
	return t.search(node.Right, value)
}
