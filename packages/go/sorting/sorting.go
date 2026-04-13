package sorting

// BubbleSort sorts a slice in place using the bubble sort algorithm.
// It repeatedly steps through the slice, compares adjacent elements,
// and swaps them if they are in the wrong order as dictated by the 'less' function.
// Time Complexity: O(n^2) in worst and average cases.
// Space Complexity: O(1) auxiliary space.
func BubbleSort[T any](arr []T, less func(a, b T) bool) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		for j := 0; j < n-i-1; j++ {
			if less(arr[j+1], arr[j]) {
				arr[j], arr[j+1] = arr[j+1], arr[j]
			}
		}
	}
}

// SelectionSort sorts a slice in place using the selection sort algorithm.
// It divides the input list into two parts: a sorted sublist and an unsorted sublist.
// It repeatedly selects the smallest (or largest) element from the unsorted sublist
// and moves it to the end of the sorted sublist.
// Time Complexity: O(n^2) in all cases.
// Space Complexity: O(1) auxiliary space.
func SelectionSort[T any](arr []T, less func(a, b T) bool) {
	n := len(arr)
	for i := 0; i < n-1; i++ {
		minIndex := i
		for j := i + 1; j < n; j++ {
			if less(arr[j], arr[minIndex]) {
				minIndex = j
			}
		}
		arr[i], arr[minIndex] = arr[minIndex], arr[i]
	}
}

// InsertionSort sorts a slice in place using the insertion sort algorithm.
// It builds the final sorted array one item at a time. It is much less efficient
// on large lists than more advanced algorithms such as quicksort, heapsort, or merge sort,
// but it is highly efficient for very small or nearly sorted datasets.
// Time Complexity: O(n^2) worst/average, O(n) best case (already sorted).
// Space Complexity: O(1) auxiliary space.
func InsertionSort[T any](arr []T, less func(a, b T) bool) {
	n := len(arr)
	for i := 1; i < n; i++ {
		key := arr[i]
		j := i - 1
		for j >= 0 && less(key, arr[j]) {
			arr[j+1] = arr[j]
			j--
		}
		arr[j+1] = key
	}
}

// HeapSort sorts a slice in place using the heap sort algorithm.
// It first builds a max-heap (using the 'less' function to establish order)
// and then repeatedly extracts the root element to move it to the end of the sorted array.
// Time Complexity: O(n log n) in all cases.
// Space Complexity: O(1) auxiliary space, making it highly memory efficient.
func HeapSort[T any](arr []T, less func(a, b T) bool) {
	n := len(arr)

	// Build max heap
	for i := n/2 - 1; i >= 0; i-- {
		heapify(arr, n, i, less)
	}

	// Extract elements from heap one by one
	for i := n - 1; i > 0; i-- {
		// Move current root to end
		arr[0], arr[i] = arr[i], arr[0]
		// Call max heapify on the reduced heap
		heapify(arr, i, 0, less)
	}
}

// heapify is a helper function for HeapSort that maintains the heap property.
// It assumes that the subtrees rooted at left and right children are already heaps.
func heapify[T any](arr []T, n, i int, less func(a, b T) bool) {
	largest := i
	left := 2*i + 1
	right := 2*i + 2

	if left < n && less(arr[largest], arr[left]) {
		largest = left
	}

	if right < n && less(arr[largest], arr[right]) {
		largest = right
	}

	if largest != i {
		arr[i], arr[largest] = arr[largest], arr[i]
		heapify(arr, n, largest, less)
	}
}
