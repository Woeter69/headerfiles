const std = @import("std");
const Allocator = std.mem.Allocator;

pub fn Stack(comptime T: type) type {
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

        pub fn push(self: *Self, item: T) !void {
            try self.items.append(self.allocator, item);
        }

        pub fn pop(self: *Self) ?T {
            return self.items.pop();
        }

        pub fn peek(self: *Self) ?T {
            if (self.items.items.len == 0) return null;
            return self.items.items[self.items.items.len - 1];
        }
    };
}