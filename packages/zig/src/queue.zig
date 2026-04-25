const std = @import("std");
const Allocator = std.mem.Allocator;

pub fn Queue(comptime T: type) type {
    return struct {
        pub const Node = struct {
            data: T,
            next: ?*Node = null,
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

        pub fn enqueue(self: *Self, data: T) !void {
            const node = try self.allocator.create(Node);
            node.* = Node{ .data = data, .next = null };

            if (self.tail) |tail| {
                tail.next = node;
            } else {
                self.head = node;
            }
            self.tail = node;
        }

        pub fn dequeue(self: *Self) ?T {
            if (self.head) |head| {
                const data = head.data;
                self.head = head.next;
                if (self.head == null) {
                    self.tail = null;
                }
                self.allocator.destroy(head);
                return data;
            }
            return null;
        }
    };
}

pub fn Deque(comptime T: type) type {
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

        pub fn pushBack(self: *Self, data: T) !void {
            const node = try self.allocator.create(Node);
            node.* = Node{ .data = data, .next = null, .prev = self.tail };
            if (self.tail) |t| t.next = node else self.head = node;
            self.tail = node;
        }

        pub fn pushFront(self: *Self, data: T) !void {
            const node = try self.allocator.create(Node);
            node.* = Node{ .data = data, .next = self.head, .prev = null };
            if (self.head) |h| h.prev = node else self.tail = node;
            self.head = node;
        }

        pub fn popFront(self: *Self) ?T {
            if (self.head) |h| {
                const d = h.data;
                self.head = h.next;
                if (self.head) |new_h| new_h.prev = null else self.tail = null;
                self.allocator.destroy(h);
                return d;
            }
            return null;
        }
        
        pub fn popBack(self: *Self) ?T {
            if (self.tail) |t| {
                const d = t.data;
                self.tail = t.prev;
                if (self.tail) |new_t| new_t.next = null else self.head = null;
                self.allocator.destroy(t);
                return d;
            }
            return null;
        }
    };
}

pub fn CircularQueue(comptime T: type) type {
    return struct {
        items: []T,
        head: usize,
        tail: usize,
        count: usize,
        capacity: usize,
        allocator: Allocator,

        const Self = @This();

        pub fn init(allocator: Allocator, capacity: usize) !Self {
            const items = try allocator.alloc(T, capacity);
            return Self{
                .items = items,
                .head = 0,
                .tail = 0,
                .count = 0,
                .capacity = capacity,
                .allocator = allocator,
            };
        }

        pub fn deinit(self: *Self) void {
            self.allocator.free(self.items);
        }

        pub fn enqueue(self: *Self, item: T) bool {
            if (self.count == self.capacity) return false;
            self.items[self.tail] = item;
            self.tail = (self.tail + 1) % self.capacity;
            self.count += 1;
            return true;
        }

        pub fn dequeue(self: *Self) ?T {
            if (self.count == 0) return null;
            const item = self.items[self.head];
            self.head = (self.head + 1) % self.capacity;
            self.count -= 1;
            return item;
        }

        pub fn isFull(self: *Self) bool {
            return self.count == self.capacity;
        }

        pub fn isEmpty(self: *Self) bool {
            return self.count == 0;
        }
    };
}