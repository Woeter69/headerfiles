package queue

import "errors"

// Queue represents a generic First-In-First-Out (FIFO) data structure.
// It is backed by a dynamic slice. Note that frequent Dequeue operations
// can cause the underlying array capacity to grow unless occasionally reallocated.
type Queue[T any] struct {
	elements []T // The underlying slice storing the queue's elements.
}

// New creates and returns a new, empty generic Queue.
func New[T any]() *Queue[T] {
	return &Queue[T]{elements: make([]T, 0)}
}

// Enqueue adds a new element containing the specified value to the back of the queue.
// Time Complexity: Amortized O(1)
func (q *Queue[T]) Enqueue(value T) {
	q.elements = append(q.elements, value)
}

// Dequeue removes and returns the front element of the queue.
// It returns an error if the queue is empty.
// Time Complexity: O(1) (Slice re-slicing)
func (q *Queue[T]) Dequeue() (T, error) {
	if q.IsEmpty() {
		var zero T
		return zero, errors.New("queue is empty")
	}
	value := q.elements[0]
	q.elements = q.elements[1:]
	return value, nil
}

// Peek returns the front element of the queue without removing it.
// It returns an error if the queue is empty.
// Time Complexity: O(1)
func (q *Queue[T]) Peek() (T, error) {
	if q.IsEmpty() {
		var zero T
		return zero, errors.New("queue is empty")
	}
	return q.elements[0], nil
}

// IsEmpty returns true if the queue contains no elements, otherwise false.
// Time Complexity: O(1)
func (q *Queue[T]) IsEmpty() bool {
	return len(q.elements) == 0
}

// Size returns the total number of elements currently in the queue.
// Time Complexity: O(1)
func (q *Queue[T]) Size() int {
	return len(q.elements)
}

// Deque represents a generic Double-Ended Queue allowing insertion and
// deletion at both ends.
type Deque[T any] struct {
	elements []T // The underlying slice storing the deque's elements.
}

// NewDeque creates and returns a new, empty generic Deque.
func NewDeque[T any]() *Deque[T] {
	return &Deque[T]{elements: make([]T, 0)}
}

// PushBack adds an element to the back of the deque.
// Time Complexity: Amortized O(1)
func (d *Deque[T]) PushBack(value T) {
	d.elements = append(d.elements, value)
}

// PushFront adds an element to the front of the deque.
// Time Complexity: O(n) because it requires shifting all existing elements.
func (d *Deque[T]) PushFront(value T) {
	d.elements = append([]T{value}, d.elements...)
}

// PopBack removes and returns the element at the back of the deque.
// Returns an error if the deque is empty.
// Time Complexity: O(1)
func (d *Deque[T]) PopBack() (T, error) {
	if len(d.elements) == 0 {
		var zero T
		return zero, errors.New("deque is empty")
	}
	index := len(d.elements) - 1
	value := d.elements[index]
	d.elements = d.elements[:index]
	return value, nil
}

// PopFront removes and returns the element at the front of the deque.
// Returns an error if the deque is empty.
// Time Complexity: O(1) (Slice re-slicing)
func (d *Deque[T]) PopFront() (T, error) {
	if len(d.elements) == 0 {
		var zero T
		return zero, errors.New("deque is empty")
	}
	value := d.elements[0]
	d.elements = d.elements[1:]
	return value, nil
}
