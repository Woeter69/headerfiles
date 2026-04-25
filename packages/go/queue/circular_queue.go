package queue

import "errors"

// CircularQueue represents a generic Circular Queue (Ring Buffer) data structure.
type CircularQueue[T any] struct {
	elements []T
	head     int
	tail     int
	size     int
	capacity int
}

// NewCircularQueue creates and returns a new CircularQueue with the specified capacity.
func NewCircularQueue[T any](capacity int) *CircularQueue[T] {
	return &CircularQueue[T]{
		elements: make([]T, capacity),
		head:     0,
		tail:     -1,
		size:     0,
		capacity: capacity,
	}
}

// Enqueue adds an element to the circular queue.
func (q *CircularQueue[T]) Enqueue(value T) error {
	if q.IsFull() {
		return errors.New("queue is full")
	}
	q.tail = (q.tail + 1) % q.capacity
	q.elements[q.tail] = value
	q.size++
	return nil
}

// Dequeue removes and returns the front element.
func (q *CircularQueue[T]) Dequeue() (T, error) {
	var zero T
	if q.IsEmpty() {
		return zero, errors.New("queue is empty")
	}
	value := q.elements[q.head]
	q.head = (q.head + 1) % q.capacity
	q.size--
	return value, nil
}

// Peek returns the front element of the queue without removing it.
func (q *CircularQueue[T]) Peek() (T, error) {
	if q.IsEmpty() {
		var zero T
		return zero, errors.New("queue is empty")
	}
	return q.elements[q.head], nil
}

// IsEmpty returns true if the queue contains no elements.
func (q *CircularQueue[T]) IsEmpty() bool {
	return q.size == 0
}

// IsFull returns true if the queue has reached its capacity.
func (q *CircularQueue[T]) IsFull() bool {
	return q.size == q.capacity
}

// Size returns the number of elements in the queue.
func (q *CircularQueue[T]) Size() int {
	return q.size
}
