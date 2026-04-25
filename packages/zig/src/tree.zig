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

pub const TrieNode = struct {
    children: std.AutoHashMap(u8, *TrieNode),
    is_end_of_word: bool,
    
    pub fn init(allocator: Allocator) TrieNode {
        return TrieNode{
            .children = std.AutoHashMap(u8, *TrieNode).init(allocator),
            .is_end_of_word = false,
        };
    }
    
    pub fn deinit(self: *TrieNode, allocator: Allocator) void {
        var it = self.children.iterator();
        while (it.next()) |entry| {
            entry.value_ptr.*.deinit(allocator);
            allocator.destroy(entry.value_ptr.*);
        }
        self.children.deinit();
    }
};

pub const Trie = struct {
    root: *TrieNode,
    allocator: Allocator,

    const Self = @This();

    pub fn init(allocator: Allocator) !Self {
        const root = try allocator.create(TrieNode);
        root.* = TrieNode.init(allocator);
        return Self{
            .root = root,
            .allocator = allocator,
        };
    }

    pub fn deinit(self: *Self) void {
        self.root.deinit(self.allocator);
        self.allocator.destroy(self.root);
    }

    pub fn insert(self: *Self, word: []const u8) !void {
        var curr = self.root;
        for (word) |c| {
            if (curr.children.get(c)) |next_node| {
                curr = next_node;
            } else {
                const new_node = try self.allocator.create(TrieNode);
                new_node.* = TrieNode.init(self.allocator);
                try curr.children.put(c, new_node);
                curr = new_node;
            }
        }
        curr.is_end_of_word = true;
    }

    pub fn search(self: *Self, word: []const u8) bool {
        var curr = self.root;
        for (word) |c| {
            if (curr.children.get(c)) |next_node| {
                curr = next_node;
            } else {
                return false;
            }
        }
        return curr.is_end_of_word;
    }
};

pub fn AVLTree(comptime T: type) type {
    return struct {
        pub const Node = struct {
            data: T,
            left: ?*Node = null,
            right: ?*Node = null,
            height: i32 = 1,
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

        fn getHeight(node: ?*Node) i32 {
            if (node) |n| return n.height;
            return 0;
        }

        fn getBalance(node: ?*Node) i32 {
            if (node) |n| return getHeight(n.left) - getHeight(n.right);
            return 0;
        }

        fn rightRotate(self: *Self, y: *Node) *Node {
            _ = self;
            const x = y.left.?;
            const T2 = x.right;

            x.right = y;
            y.left = T2;

            y.height = @max(getHeight(y.left), getHeight(y.right)) + 1;
            x.height = @max(getHeight(x.left), getHeight(x.right)) + 1;

            return x;
        }

        fn leftRotate(self: *Self, x: *Node) *Node {
            _ = self;
            const y = x.right.?;
            const T2 = y.left;

            y.left = x;
            x.right = T2;

            x.height = @max(getHeight(x.left), getHeight(x.right)) + 1;
            y.height = @max(getHeight(y.left), getHeight(y.right)) + 1;

            return y;
        }

        pub fn insert(self: *Self, data: T) !void {
            self.root = try self.insertNode(self.root, data);
        }

        fn insertNode(self: *Self, node: ?*Node, data: T) !*Node {
            if (node == null) {
                const new_node = try self.allocator.create(Node);
                new_node.* = Node{ .data = data };
                return new_node;
            }

            const n = node.?;
            if (data < n.data) {
                n.left = try self.insertNode(n.left, data);
            } else if (data > n.data) {
                n.right = try self.insertNode(n.right, data);
            } else {
                return n; // Duplicates not allowed
            }

            n.height = 1 + @max(getHeight(n.left), getHeight(n.right));
            const balance = getBalance(n);

            // Left Left Case
            if (balance > 1 and data < n.left.?.data) {
                return self.rightRotate(n);
            }
            // Right Right Case
            if (balance < -1 and data > n.right.?.data) {
                return self.leftRotate(n);
            }
            // Left Right Case
            if (balance > 1 and data > n.left.?.data) {
                n.left = self.leftRotate(n.left.?);
                return self.rightRotate(n);
            }
            // Right Left Case
            if (balance < -1 and data < n.right.?.data) {
                n.right = self.rightRotate(n.right.?);
                return self.leftRotate(n);
            }

            return n;
        }
    };
}