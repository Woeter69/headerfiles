package search

// LinearSearch iterates through a slice to find a target value.
// It compares each element with the target and returns the zero-based index of the
// first occurrence.
// If the target is not found in the slice, it returns -1.
// Time Complexity: O(n), where n is the length of the slice.
// Space Complexity: O(1)
func LinearSearch[T comparable](arr []T, target T) int {
	for i, val := range arr {
		if val == target {
			return i
		}
	}
	return -1
}

// BinarySearch efficiently searches for a target value within a sorted slice.
// It repeatedly divides the search interval in half.
// The provided slice MUST be sorted according to the logic in the 'less' function,
// otherwise the behavior is undefined.
// The 'less' function should return true if 'a' is strictly less than 'b'.
// Returns the zero-based index of the target if found, or -1 if it's not present.
// Time Complexity: O(log n), where n is the length of the slice.
// Space Complexity: O(1)
func BinarySearch[T any](arr []T, target T, less func(a, b T) bool) int {
	low := 0
	high := len(arr) - 1

	for low <= high {
		mid := low + (high-low)/2
		// If arr[mid] is not less than target, and target is not less than arr[mid], they are equal.
		if !less(arr[mid], target) && !less(target, arr[mid]) {
			return mid
		}
		// If arr[mid] is less than the target, target must be in the right half.
		if less(arr[mid], target) {
			low = mid + 1
		} else {
			// Otherwise, target must be in the left half.
			high = mid - 1
		}
	}
	return -1 // Target not found
}
