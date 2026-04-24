const std = @import("std");
const Allocator = std.mem.Allocator;

pub fn Heap(comptime T: type, comptime compareFn: fn (a: T, b: T) bool) type {
    return struct {
        items: std.ArrayList(T),
        allocator: Allocator,

        const Self = @This();

        pub fn init(allocator: Allocator) Self {
            return Self{ .items = .empty, .allocator = allocator };
        }

        pub fn deinit(self: *Self) void {
            self.items.deinit(self.allocator);
        }

        pub fn insert(self: *Self, item: T) !void {
            try self.items.append(self.allocator, item);
            self.siftUp(self.items.items.len - 1);
        }

        pub fn extract(self: *Self) ?T {
            if (self.items.items.len == 0) return null;
            const root = self.items.items[0];
            const last = self.items.pop().?;
            if (self.items.items.len > 0) {
                self.items.items[0] = last;
                self.siftDown(0);
            }
            return root;
        }

        fn siftUp(self: *Self, index: usize) void {
            var curr = index;
            while (curr > 0) {
                const parent = (curr - 1) / 2;
                if (compareFn(self.items.items[curr], self.items.items[parent])) {
                    std.mem.swap(T, &self.items.items[curr], &self.items.items[parent]);
                    curr = parent;
                } else {
                    break;
                }
            }
        }

        fn siftDown(self: *Self, index: usize) void {
            var curr = index;
            const len = self.items.items.len;
            while (true) {
                var smallestOrLargest = curr;
                const left = 2 * curr + 1;
                const right = 2 * curr + 2;

                if (left < len and compareFn(self.items.items[left], self.items.items[smallestOrLargest])) {
                    smallestOrLargest = left;
                }
                if (right < len and compareFn(self.items.items[right], self.items.items[smallestOrLargest])) {
                    smallestOrLargest = right;
                }

                if (smallestOrLargest != curr) {
                    std.mem.swap(T, &self.items.items[curr], &self.items.items[smallestOrLargest]);
                    curr = smallestOrLargest;
                } else {
                    break;
                }
            }
        }
    };
}