const std = @import("std");

pub fn linearSearch(comptime T: type, items: []const T, target: T) ?usize {
    for (items, 0..) |item, i| {
        if (item == target) return i;
    }
    return null;
}

pub fn binarySearch(comptime T: type, items: []const T, target: T) ?usize {
    if (items.len == 0) return null;
    var left: usize = 0;
    var right: usize = items.len - 1;

    while (left <= right) {
        const mid = left + (right - left) / 2;
        if (items[mid] == target) return mid;
        if (items[mid] < target) {
            left = mid + 1;
        } else {
            if (mid == 0) return null;
            right = mid - 1;
        }
    }
    return null;
}