package linkedlist

import "errors"

// DNode represents a node in a doubly linked list.
// It holds a generic Value and pointers to both the Next and Previous nodes.
type DNode[T any] struct {
	Value      T           // The data stored in the node.
	Next, Prev *DNode[T]   // Pointers to adjacent nodes.
}

// DoublyLinkedList represents a generic bi-directional linked list.
// It maintains pointers to the Head (first element) and Tail (last element)
// to allow efficient O(1) insertions and deletions at both ends.
type DoublyLinkedList[T any] struct {
	Head, Tail *DNode[T] // Pointers to the ends of the list.
	Size       int       // The total number of elements currently in the list.
}

// AddAtStart adds a new element containing the specified value to the beginning of the list.
// The new element becomes the new Head, and its Next pointer points to the old Head.
// Time Complexity: O(1)
func (l *DoublyLinkedList[T]) AddAtStart(value T) {
	newNode := &DNode[T]{Value: value, Next: l.Head}
	if l.Head != nil {
		l.Head.Prev = newNode
	}
	l.Head = newNode
	if l.Tail == nil {
		l.Tail = newNode
	}
	l.Size++
}

// AddAtEnd adds a new element containing the specified value to the end of the list.
// The new element becomes the new Tail, and its Prev pointer points to the old Tail.
// Time Complexity: O(1)
func (l *DoublyLinkedList[T]) AddAtEnd(value T) {
	newNode := &DNode[T]{Value: value, Prev: l.Tail}
	if l.Tail != nil {
		l.Tail.Next = newNode
	}
	l.Tail = newNode
	if l.Head == nil {
		l.Head = newNode
	}
	l.Size++
}

// RemoveFromStart removes the first element from the list and returns its value.
// It safely updates the Head pointer and returns an error if the list is empty.
// Time Complexity: O(1)
func (l *DoublyLinkedList[T]) RemoveFromStart() (T, error) {
	var zero T
	if l.Head == nil {
		return zero, errors.New("list is empty")
	}
	val := l.Head.Value
	l.Head = l.Head.Next
	if l.Head != nil {
		l.Head.Prev = nil
	} else {
		l.Tail = nil
	}
	l.Size--
	return val, nil
}

// RemoveFromEnd removes the last element from the list and returns its value.
// Unlike a singly linked list, this relies on the Tail's Prev pointer for an O(1) removal.
// Returns an error if the list is empty.
// Time Complexity: O(1)
func (l *DoublyLinkedList[T]) RemoveFromEnd() (T, error) {
	var zero T
	if l.Tail == nil {
		return zero, errors.New("list is empty")
	}
	val := l.Tail.Value
	l.Tail = l.Tail.Prev
	if l.Tail != nil {
		l.Tail.Next = nil
	} else {
		l.Head = nil
	}
	l.Size--
	return val, nil
}

// RemoveAt removes the element at the specified zero-based index and returns its value.
// It optimizes boundary removals and traverses the list for middle removals.
// It returns an error if the index is out of bounds.
// Time Complexity: O(n) for middle elements, O(1) for boundaries.
func (l *DoublyLinkedList[T]) RemoveAt(index int) (T, error) {
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
	for i := 0; i < index; i++ {
		curr = curr.Next
	}

	curr.Prev.Next = curr.Next
	curr.Next.Prev = curr.Prev
	l.Size--
	return curr.Value, nil
}
