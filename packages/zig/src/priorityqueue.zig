const std = @import("std");
const Heap = @import("heap.zig").Heap;
const Allocator = std.mem.Allocator;

pub fn PriorityQueue(comptime T: type, comptime compareFn: fn (a: T, b: T) bool) type {
    return struct {
        heap: Heap(T, compareFn),

        const Self = @This();

        pub fn init(allocator: Allocator) Self {
            return Self{ .heap = Heap(T, compareFn).init(allocator) };
        }

        pub fn deinit(self: *Self) void {
            self.heap.deinit();
        }

        pub fn enqueue(self: *Self, item: T) !void {
            try self.heap.insert(item);
        }

        pub fn dequeue(self: *Self) ?T {
            return self.heap.extract();
        }
    };
}