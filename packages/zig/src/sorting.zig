const std = @import("std");

pub fn bubbleSort(comptime T: type, items: []T) void {
    var n = items.len;
    while (n > 1) {
        var newn: usize = 0;
        var i: usize = 1;
        while (i < n) : (i += 1) {
            if (items[i - 1] > items[i]) {
                std.mem.swap(T, &items[i - 1], &items[i]);
                newn = i;
            }
        }
        n = newn;
    }
}

pub fn selectionSort(comptime T: type, items: []T) void {
    if (items.len == 0) return;
    for (0..items.len - 1) |i| {
        var min_idx = i;
        for (i + 1..items.len) |j| {
            if (items[j] < items[min_idx]) {
                min_idx = j;
            }
        }
        std.mem.swap(T, &items[i], &items[min_idx]);
    }
}

pub fn insertionSort(comptime T: type, items: []T) void {
    if (items.len == 0) return;
    for (1..items.len) |i| {
        const key = items[i];
        var j: isize = @intCast(i - 1);
        while (j >= 0 and items[@intCast(j)] > key) : (j -= 1) {
            items[@intCast(j + 1)] = items[@intCast(j)];
        }
        items[@intCast(j + 1)] = key;
    }
}

pub fn heapSort(comptime T: type, items: []T) void {
    if (items.len == 0) return;
    const n = items.len;

    // Build heap (rearrange array)
    var i: isize = @intCast((n / 2) - 1);
    while (i >= 0) : (i -= 1) {
        heapify(T, items, n, @intCast(i));
    }

    // One by one extract an element from heap
    i = @intCast(n - 1);
    while (i > 0) : (i -= 1) {
        std.mem.swap(T, &items[0], &items[@intCast(i)]);
        heapify(T, items, @intCast(i), 0);
    }
}

fn heapify(comptime T: type, items: []T, n: usize, i: usize) void {
    var largest = i;
    const l = 2 * i + 1;
    const r = 2 * i + 2;

    if (l < n and items[l] > items[largest]) {
        largest = l;
    }
    if (r < n and items[r] > items[largest]) {
        largest = r;
    }
    if (largest != i) {
        std.mem.swap(T, &items[i], &items[largest]);
        heapify(T, items, n, largest);
    }
}

pub fn quickSort(comptime T: type, items: []T) void {
    if (items.len <= 1) return;
    quickSortImpl(T, items, 0, @as(isize, @intCast(items.len - 1)));
}

fn quickSortImpl(comptime T: type, items: []T, low: isize, high: isize) void {
    if (low < high) {
        const pi = partition(T, items, low, high);
        quickSortImpl(T, items, low, pi - 1);
        quickSortImpl(T, items, pi + 1, high);
    }
}

fn partition(comptime T: type, items: []T, low: isize, high: isize) isize {
    const pivot = items[@intCast(high)];
    var i = low - 1;

    var j = low;
    while (j <= high - 1) : (j += 1) {
        if (items[@intCast(j)] < pivot) {
            i += 1;
            std.mem.swap(T, &items[@intCast(i)], &items[@intCast(j)]);
        }
    }
    std.mem.swap(T, &items[@intCast(i + 1)], &items[@intCast(high)]);
    return i + 1;
}

pub fn mergeSort(comptime T: type, items: []T, allocator: std.mem.Allocator) !void {
    if (items.len <= 1) return;
    const mid = items.len / 2;
    try mergeSort(T, items[0..mid], allocator);
    try mergeSort(T, items[mid..], allocator);

    const left = items[0..mid];
    const right = items[mid..];

    var temp = try allocator.alloc(T, items.len);
    defer allocator.free(temp);

    var i: usize = 0;
    var j: usize = 0;
    var k: usize = 0;

    while (i < left.len and j < right.len) {
        if (left[i] <= right[j]) {
            temp[k] = left[i];
            i += 1;
        } else {
            temp[k] = right[j];
            j += 1;
        }
        k += 1;
    }

    while (i < left.len) {
        temp[k] = left[i];
        i += 1;
        k += 1;
    }

    while (j < right.len) {
        temp[k] = right[j];
        j += 1;
        k += 1;
    }

    for (temp, 0..) |val, idx| {
        items[idx] = val;
    }
}