package sorting

// QuickSort sorts a slice in place using the quicksort algorithm.
// Time Complexity: O(n log n) average, O(n^2) worst case.
func QuickSort[T any](arr []T, less func(a, b T) bool) {
	if len(arr) < 2 {
		return
	}
	quickSort(arr, 0, len(arr)-1, less)
}

func quickSort[T any](arr []T, low, high int, less func(a, b T) bool) {
	if low < high {
		pi := partition(arr, low, high, less)
		quickSort(arr, low, pi-1, less)
		quickSort(arr, pi+1, high, less)
	}
}

func partition[T any](arr []T, low, high int, less func(a, b T) bool) int {
	pivot := arr[high]
	i := low - 1
	for j := low; j < high; j++ {
		if less(arr[j], pivot) {
			i++
			arr[i], arr[j] = arr[j], arr[i]
		}
	}
	arr[i+1], arr[high] = arr[high], arr[i+1]
	return i + 1
}
