package sorting

// MergeSort sorts a slice using the merge sort algorithm.
// It returns a new sorted slice.
// Time Complexity: O(n log n) in all cases.
func MergeSort[T any](arr []T, less func(a, b T) bool) []T {
	if len(arr) <= 1 {
		return arr
	}
	mid := len(arr) / 2
	left := MergeSort(arr[:mid], less)
	right := MergeSort(arr[mid:], less)
	return merge(left, right, less)
}

func merge[T any](left, right []T, less func(a, b T) bool) []T {
	result := make([]T, 0, len(left)+len(right))
	i, j := 0, 0
	for i < len(left) && j < len(right) {
		if less(right[j], left[i]) {
			result = append(result, right[j])
			j++
		} else {
			result = append(result, left[i])
			i++
		}
	}
	result = append(result, left[i:]...)
	result = append(result, right[j:]...)
	return result
}
