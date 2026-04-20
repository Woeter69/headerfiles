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