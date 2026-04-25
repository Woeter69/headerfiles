pub fn bubble_sort<T: Ord>(arr: &mut [T]) {
    let len = arr.len();
    if len == 0 { return; }
    for i in 0..len {
        for j in 0..len - 1 - i {
            if arr[j] > arr[j + 1] {
                arr.swap(j, j + 1);
            }
        }
    }
}

pub fn selection_sort<T: Ord>(arr: &mut [T]) {
    let len = arr.len();
    if len == 0 { return; }
    for i in 0..len {
        let mut min_idx = i;
        for j in i + 1..len {
            if arr[j] < arr[min_idx] {
                min_idx = j;
            }
        }
        arr.swap(i, min_idx);
    }
}

pub fn insertion_sort<T: Ord + Clone>(arr: &mut [T]) {
    let len = arr.len();
    if len == 0 { return; }
    for i in 1..len {
        let mut j = i;
        while j > 0 && arr[j - 1] > arr[j] {
            arr.swap(j - 1, j);
            j -= 1;
        }
    }
}

pub fn heap_sort<T: Ord>(arr: &mut [T]) {
    let len = arr.len();
    if len == 0 { return; }
    for i in (0..len / 2).rev() {
        heapify(arr, len, i);
    }
    for i in (1..len).rev() {
        arr.swap(0, i);
        heapify(arr, i, 0);
    }
}

fn heapify<T: Ord>(arr: &mut [T], n: usize, i: usize) {
    let mut largest = i;
    let l = 2 * i + 1;
    let r = 2 * i + 2;
    if l < n && arr[l] > arr[largest] {
        largest = l;
    }
    if r < n && arr[r] > arr[largest] {
        largest = r;
    }
    if largest != i {
        arr.swap(i, largest);
        heapify(arr, n, largest);
    }
}

pub fn quick_sort<T: Ord + Clone>(arr: &mut [T]) {
    let len = arr.len();
    if len < 2 {
        return;
    }
    quick_sort_helper(arr, 0, len - 1);
}

fn quick_sort_helper<T: Ord + Clone>(arr: &mut [T], low: usize, high: usize) {
    if low < high {
        let p = partition(arr, low, high);
        if p > 0 {
            quick_sort_helper(arr, low, p - 1);
        }
        quick_sort_helper(arr, p + 1, high);
    }
}

fn partition<T: Ord + Clone>(arr: &mut [T], low: usize, high: usize) -> usize {
    let pivot = arr[high].clone();
    let mut i = low;
    for j in low..high {
        if arr[j] <= pivot {
            arr.swap(i, j);
            i += 1;
        }
    }
    arr.swap(i, high);
    i
}

pub fn merge_sort<T: Ord + Clone>(arr: &mut [T]) {
    let len = arr.len();
    if len < 2 {
        return;
    }
    let mid = len / 2;
    
    {
        let (left_slice, right_slice) = arr.split_at_mut(mid);
        merge_sort(left_slice);
        merge_sort(right_slice);
    }

    let left = arr[0..mid].to_vec();
    let right = arr[mid..len].to_vec();
    
    let mut i = 0;
    let mut j = 0;
    let mut k = 0;

    while i < left.len() && j < right.len() {
        if left[i] <= right[j] {
            arr[k] = left[i].clone();
            i += 1;
        } else {
            arr[k] = right[j].clone();
            j += 1;
        }
        k += 1;
    }
    while i < left.len() {
        arr[k] = left[i].clone();
        i += 1;
        k += 1;
    }
    while j < right.len() {
        arr[k] = right[j].clone();
        j += 1;
        k += 1;
    }
}
