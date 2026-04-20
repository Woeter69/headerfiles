const std = @import("std");
const Allocator = std.mem.Allocator;

pub fn BST(comptime T: type) type {
    return struct {
        pub const Node = struct {
            data: T,
            left: ?*Node = null,
            right: ?*Node = null,
        };

        root: ?*Node = null,
        allocator: Allocator,

        const Self = @This();

        pub fn init(allocator: Allocator) Self {
            return Self{ .allocator = allocator };
        }

        pub fn deinit(self: *Self) void {
            self.freeNode(self.root);
        }

        fn freeNode(self: *Self, node: ?*Node) void {
            if (node) |n| {
                self.freeNode(n.left);
                self.freeNode(n.right);
                self.allocator.destroy(n);
            }
        }

        pub fn insert(self: *Self, data: T) !void {
            const new_node = try self.allocator.create(Node);
            new_node.* = Node{ .data = data };

            if (self.root == null) {
                self.root = new_node;
                return;
            }

            var curr = self.root;
            while (curr) |n| {
                if (data < n.data) {
                    if (n.left == null) {
                        n.left = new_node;
                        break;
                    } else {
                        curr = n.left;
                    }
                } else {
                    if (n.right == null) {
                        n.right = new_node;
                        break;
                    } else {
                        curr = n.right;
                    }
                }
            }
        }
    };
}

pub fn NaryTree(comptime T: type) type {
    return struct {
        pub const Node = struct {
            data: T,
            children: std.ArrayList(*Node),
        };

        root: ?*Node = null,
        allocator: Allocator,

        const Self = @This();

        pub fn init(allocator: Allocator) Self {
            return Self{ .allocator = allocator };
        }

        pub fn createNode(self: *Self, data: T) !*Node {
            const node = try self.allocator.create(Node);
            node.* = Node{
                .data = data,
                .children = .empty,
            };
            return node;
        }

        pub fn deinit(self: *Self) void {
            self.freeNode(self.root);
        }

        fn freeNode(self: *Self, node: ?*Node) void {
            if (node) |n| {
                for (n.children.items) |child| {
                    self.freeNode(child);
                }
                n.children.deinit(self.allocator);
                self.allocator.destroy(n);
            }
        }
    };
}