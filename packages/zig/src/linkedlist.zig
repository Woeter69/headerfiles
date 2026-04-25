const std = @import("std");
const Allocator = std.mem.Allocator;

pub fn SinglyLinkedList(comptime T: type) type {
    return struct {
        pub const Node = struct {
            data: T,
            next: ?*Node = null,
        };

        head: ?*Node = null,
        allocator: Allocator,

        const Self = @This();

        pub fn init(allocator: Allocator) Self {
            return Self{ .allocator = allocator };
        }

        pub fn deinit(self: *Self) void {
            var curr = self.head;
            while (curr) |node| {
                const next = node.next;
                self.allocator.destroy(node);
                curr = next;
            }
        }

        pub fn append(self: *Self, data: T) !void {
            const node = try self.allocator.create(Node);
            node.* = Node{ .data = data, .next = null };

            if (self.head == null) {
                self.head = node;
            } else {
                var curr = self.head;
                while (curr.?.next != null) {
                    curr = curr.?.next;
                }
                curr.?.next = node;
            }
        }

        pub fn reverse(self: *Self) void {
            var prev: ?*Node = null;
            var curr = self.head;
            var next: ?*Node = null;
            while (curr) |node| {
                next = node.next;
                node.next = prev;
                prev = node;
                curr = next;
            }
            self.head = prev;
        }

        pub fn hasCycle(self: *Self) bool {
            if (self.head == null) return false;
            var slow = self.head;
            var fast = self.head;
            while (fast != null and fast.?.next != null) {
                slow = slow.?.next;
                fast = fast.?.next.?.next;
                if (slow == fast) return true;
            }
            return false;
        }
    };
}

pub fn DoublyLinkedList(comptime T: type) type {
    return struct {
        pub const Node = struct {
            data: T,
            next: ?*Node = null,
            prev: ?*Node = null,
        };

        head: ?*Node = null,
        tail: ?*Node = null,
        allocator: Allocator,

        const Self = @This();

        pub fn init(allocator: Allocator) Self {
            return Self{ .allocator = allocator };
        }

        pub fn deinit(self: *Self) void {
            var curr = self.head;
            while (curr) |node| {
                const next = node.next;
                self.allocator.destroy(node);
                curr = next;
            }
        }

        pub fn append(self: *Self, data: T) !void {
            const node = try self.allocator.create(Node);
            node.* = Node{ .data = data, .next = null, .prev = self.tail };

            if (self.tail) |tail| {
                tail.next = node;
            } else {
                self.head = node;
            }
            self.tail = node;
        }
    };
}