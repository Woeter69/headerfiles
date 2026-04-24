package priorityqueue

import "github.com/Woeter69/headerfiles/packages/heap"

// Item represents a single element stored in the priority queue.
// It pairs a generic Value with an integer Priority score.
type Item[T any] struct {
	Value    T   // The actual data.
	Priority int // The priority score determining extraction order.
}

// PriorityQueue represents a generic priority queue.
// It leverages the custom 'heap' package to efficiently order items.
type PriorityQueue[T any] struct {
	h *heap.Heap[Item[T]] // The underlying heap storing the items.
}

// NewMinPQ creates and returns a new min-priority queue.
// In a MinPQ, elements with the LOWEST priority integer are popped first.
func NewMinPQ[T any]() *PriorityQueue[T] {
	return &PriorityQueue[T]{
		h: heap.New(func(a, b Item[T]) bool {
			return a.Priority < b.Priority
		}),
	}
}

// NewMaxPQ creates and returns a new max-priority queue.
// In a MaxPQ, elements with the HIGHEST priority integer are popped first.
func NewMaxPQ[T any]() *PriorityQueue[T] {
	return &PriorityQueue[T]{
		h: heap.New(func(a, b Item[T]) bool {
			return a.Priority > b.Priority
		}),
	}
}

// Push adds a new item with the given value and priority score to the queue.
// Time Complexity: O(log n)
func (pq *PriorityQueue[T]) Push(value T, priority int) {
	pq.h.Push(Item[T]{Value: value, Priority: priority})
}

// Pop removes and returns the value of the item with the highest (or lowest) priority.
// It returns false if the priority queue is empty.
// Time Complexity: O(log n)
func (pq *PriorityQueue[T]) Pop() (T, bool) {
	item, ok := pq.h.Pop()
	if !ok {
		var zero T
		return zero, false
	}
	return item.Value, true
}

// Peek returns the value of the item with the highest (or lowest) priority
// without removing it from the queue.
// It returns false if the priority queue is empty.
// Time Complexity: O(1)
func (pq *PriorityQueue[T]) Peek() (T, bool) {
	item, ok := pq.h.Peek()
	if !ok {
		var zero T
		return zero, false
	}
	return item.Value, true
}

// Size returns the total number of items currently in the priority queue.
// Time Complexity: O(1)
func (pq *PriorityQueue[T]) Size() int {
	return pq.h.Size()
}
