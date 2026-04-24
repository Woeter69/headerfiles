package stack

import "errors"

// Stack represents a generic Last-In-First-Out (LIFO) data structure.
// It is backed by a dynamic slice, allowing it to grow automatically.
type Stack[T any] struct {
	elements []T // The underlying slice storing the stack's elements.
}

// New creates and returns a new, empty generic Stack.
func New[T any]() *Stack[T] {
	return &Stack[T]{elements: make([]T, 0)}
}

// Push adds a new element containing the specified value to the top of the stack.
// Time Complexity: Amortized O(1)
func (s *Stack[T]) Push(value T) {
	s.elements = append(s.elements, value)
}

// Pop removes and returns the top element of the stack.
// It returns an error if the stack is empty.
// Time Complexity: O(1)
func (s *Stack[T]) Pop() (T, error) {
	if s.IsEmpty() {
		var zero T
		return zero, errors.New("stack is empty")
	}
	index := len(s.elements) - 1
	value := s.elements[index]
	s.elements = s.elements[:index]
	return value, nil
}

// Peek returns the top element of the stack without removing it.
// It returns an error if the stack is empty.
// Time Complexity: O(1)
func (s *Stack[T]) Peek() (T, error) {
	if s.IsEmpty() {
		var zero T
		return zero, errors.New("stack is empty")
	}
	return s.elements[len(s.elements)-1], nil
}

// IsEmpty returns true if the stack contains no elements, otherwise false.
// Time Complexity: O(1)
func (s *Stack[T]) IsEmpty() bool {
	return len(s.elements) == 0
}

// Size returns the total number of elements currently in the stack.
// Time Complexity: O(1)
func (s *Stack[T]) Size() int {
	return len(s.elements)
}
