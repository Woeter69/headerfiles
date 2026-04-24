package heap

// Heap represents a generic binary heap data structure.
// It can function as either a Min-Heap or a Max-Heap, depending entirely
// on the logic provided in the 'less' comparator function during initialization.
// The heap is implemented using a dynamic array (slice).
type Heap[T any] struct {
	elements []T               // The underlying slice representing the binary tree.
	less     func(a, b T) bool // Comparator function determining heap property.
}

// New creates and returns a new, empty Heap.
// The 'less' function determines the heap order:
// - Min-Heap: func(a, b T) bool { return a < b }
// - Max-Heap: func(a, b T) bool { return a > b }
func New[T any](less func(a, b T) bool) *Heap[T] {
	return &Heap[T]{
		elements: make([]T, 0),
		less:     less,
	}
}

// Push adds a new element to the heap while maintaining the heap property.
// Time Complexity: O(log n)
func (h *Heap[T]) Push(value T) {
	h.elements = append(h.elements, value)
	h.up(len(h.elements) - 1)
}

// Pop removes and returns the root element of the heap (the minimum or maximum value).
// It returns false if the heap is empty.
// Time Complexity: O(log n)
func (h *Heap[T]) Pop() (T, bool) {
	if len(h.elements) == 0 {
		var zero T
		return zero, false
	}
	n := len(h.elements) - 1
	h.swap(0, n)
	h.down(0, n)
	
	val := h.elements[n]
	h.elements = h.elements[:n]
	return val, true
}

// Peek returns the root element of the heap without removing it.
// It returns false if the heap is empty.
// Time Complexity: O(1)
func (h *Heap[T]) Peek() (T, bool) {
	if len(h.elements) == 0 {
		var zero T
		return zero, false
	}
	return h.elements[0], true
}

// up moves the element at index j up the tree to restore the heap property.
func (h *Heap[T]) up(j int) {
	for {
		i := (j - 1) / 2 // Calculate parent index
		if i == j || !h.less(h.elements[j], h.elements[i]) {
			break
		}
		h.swap(i, j)
		j = i
	}
}

// down moves the element at index i0 down the tree to restore the heap property.
func (h *Heap[T]) down(i0, n int) {
	i := i0
	for {
		j1 := 2*i + 1
		if j1 >= n || j1 < 0 { // j1 < 0 detects integer overflow
			break
		}
		j := j1 // Assume left child is the target
		if j2 := j1 + 1; j2 < n && h.less(h.elements[j2], h.elements[j1]) {
			j = j2 // Right child is the better target
		}
		if !h.less(h.elements[j], h.elements[i]) {
			break
		}
		h.swap(i, j)
		i = j
	}
}

// swap is a helper function to exchange two elements in the underlying slice.
func (h *Heap[T]) swap(i, j int) {
	h.elements[i], h.elements[j] = h.elements[j], h.elements[i]
}

// Size returns the total number of elements currently in the heap.
// Time Complexity: O(1)
func (h *Heap[T]) Size() int {
	return len(h.elements)
}
