pub fn linear_search<T: Eq>(arr: &[T], target: &T) -> Option<usize> {
    for (i, item) in arr.iter().enumerate() {
        if item == target {
            return Some(i);
        }
    }
    None
}

pub fn binary_search<T: Ord>(arr: &[T], target: &T) -> Option<usize> {
    let mut left = 0;
    let mut right = arr.len();
    while left < right {
        let mid = left + (right - left) / 2;
        if &arr[mid] == target {
            return Some(mid);
        } else if &arr[mid] < target {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    None
}
