package linkedlist

import "errors"

// Node represents a single element in a singly linked list.
// It holds a generic Value and a pointer to the Next node in the sequence.
type Node[T any] struct {
	Value T         // The data stored in the node.
	Next  *Node[T]  // Pointer to the next node in the list.
}

// LinkedList represents a generic singly linked list data structure.
// It maintains pointers to the Head (first element) and Tail (last element)
// to allow O(1) insertions at both ends, along with the total Size of the list.
type LinkedList[T any] struct {
	Head *Node[T] // Pointer to the first element in the list.
	Tail *Node[T] // Pointer to the last element in the list.
	Size int      // The total number of elements currently in the list.
}

// AddAtEnd appends a new element containing the specified value to the end of the list.
// If the list is empty, the new element becomes both the Head and the Tail.
// Time Complexity: O(1)
func (l *LinkedList[T]) AddAtEnd(value T) {
	newNode := &Node[T]{Value: value}
	if l.Head == nil {
		l.Head = newNode
		l.Tail = newNode
	} else {
		l.Tail.Next = newNode
		l.Tail = newNode
	}
	l.Size++
}

// AddAtStart inserts a new element containing the specified value at the beginning of the list.
// The new element becomes the new Head of the list.
// Time Complexity: O(1)
func (l *LinkedList[T]) AddAtStart(value T) {
	newNode := &Node[T]{Value: value, Next: l.Head}
	l.Head = newNode
	if l.Tail == nil {
		l.Tail = newNode
	}
	l.Size++
}

// RemoveFromStart removes the first element from the list and returns its value.
// It returns an error if the list is empty.
// Time Complexity: O(1)
func (l *LinkedList[T]) RemoveFromStart() (T, error) {
	var zero T
	if l.Head == nil {
		return zero, errors.New("list is empty")
	}
	val := l.Head.Value
	l.Head = l.Head.Next
	if l.Head == nil {
		l.Tail = nil
	}
	l.Size--
	return val, nil
}

// RemoveFromEnd removes the last element from the list and returns its value.
// It returns an error if the list is empty.
// Since it's a singly linked list, it traverses to the second-to-last element
// to update the Tail pointer.
// Time Complexity: O(n)
func (l *LinkedList[T]) RemoveFromEnd() (T, error) {
	var zero T
	if l.Head == nil {
		return zero, errors.New("list is empty")
	}
	
	if l.Head == l.Tail {
		val := l.Head.Value
		l.Head = nil
		l.Tail = nil
		l.Size--
		return val, nil
	}

	curr := l.Head
	for curr.Next != l.Tail {
		curr = curr.Next
	}

	val := l.Tail.Value
	curr.Next = nil
	l.Tail = curr
	l.Size--
	return val, nil
}

// RemoveAt removes the element at the specified zero-based index and returns its value.
// It returns an error if the index is out of bounds (index < 0 || index >= Size).
// Time Complexity: O(n) for middle elements, O(1) for index 0.
func (l *LinkedList[T]) RemoveAt(index int) (T, error) {
	var zero T
	if index < 0 || index >= l.Size {
		return zero, errors.New("index out of bounds")
	}

	if index == 0 {
		return l.RemoveFromStart()
	}
	
	if index == l.Size-1 {
		return l.RemoveFromEnd()
	}

	curr := l.Head
	for i := 0; i < index-1; i++ {
		curr = curr.Next
	}

	val := curr.Next.Value
	curr.Next = curr.Next.Next
	l.Size--
	return val, nil
}

// Get retrieves the value of the element at the specified zero-based index
// without removing it from the list.
// It returns an error if the index is out of bounds.
// Time Complexity: O(n)
func (l *LinkedList[T]) Get(index int) (T, error) {
	var zero T
	if index < 0 || index >= l.Size {
		return zero, errors.New("index out of bounds")
	}
	curr := l.Head
	for i := 0; i < index; i++ {
		curr = curr.Next
	}
	return curr.Value, nil
}
