const std = @import("std");
const Allocator = std.mem.Allocator;

pub const Edge = struct {
    u: usize,
    v: usize,
    weight: i32,
};

pub fn Graph() type {
    return struct {
        adjList: std.AutoHashMap(usize, std.ArrayList(usize)),
        edges: std.ArrayList(Edge),
        allocator: Allocator,

        const Self = @This();

        pub fn init(allocator: Allocator) Self {
            return Self{
                .adjList = std.AutoHashMap(usize, std.ArrayList(usize)).init(allocator),
                .edges = .empty,
                .allocator = allocator,
            };
        }

        pub fn deinit(self: *Self) void {
            var it = self.adjList.iterator();
            while (it.next()) |entry| {
                entry.value_ptr.deinit(self.allocator);
            }
            self.adjList.deinit();
            self.edges.deinit(self.allocator);
        }

        pub fn addEdge(self: *Self, u: usize, v: usize, weight: i32) !void {
            const entry = try self.adjList.getOrPut(u);
            if (!entry.found_existing) {
                entry.value_ptr.* = .empty;
            }
            try entry.value_ptr.append(self.allocator, v);

            try self.edges.append(self.allocator, Edge{ .u = u, .v = v, .weight = weight });
        }

        pub fn bfs(self: *Self, start: usize, out: *std.ArrayList(usize)) !void {
            var visited = std.AutoHashMap(usize, void).init(self.allocator);
            defer visited.deinit();
            
            var queue: std.ArrayList(usize) = .empty;
            defer queue.deinit(self.allocator);

            try queue.append(self.allocator, start);
            try visited.put(start, {});

            while (queue.items.len > 0) {
                const u = queue.orderedRemove(0);
                try out.append(self.allocator, u);

                if (self.adjList.get(u)) |neighbors| {
                    for (neighbors.items) |v| {
                        if (!visited.contains(v)) {
                            try visited.put(v, {});
                            try queue.append(self.allocator, v);
                        }
                    }
                }
            }
        }

        pub fn dfs(self: *Self, start: usize, out: *std.ArrayList(usize)) !void {
            var visited = std.AutoHashMap(usize, void).init(self.allocator);
            defer visited.deinit();
            try self.dfsUtil(start, &visited, out);
        }

        fn dfsUtil(self: *Self, u: usize, visited: *std.AutoHashMap(usize, void), out: *std.ArrayList(usize)) !void {
            try visited.put(u, {});
            try out.append(self.allocator, u);

            if (self.adjList.get(u)) |neighbors| {
                for (neighbors.items) |v| {
                    if (!visited.contains(v)) {
                        try self.dfsUtil(v, visited, out);
                    }
                }
            }
        }

        pub fn kruskalMST(self: *Self) !std.ArrayList(Edge) {
            var result: std.ArrayList(Edge) = .empty;
            
            // Sort edges
            const edges_copy = try self.allocator.alloc(Edge, self.edges.items.len);
            defer self.allocator.free(edges_copy);
            @memcpy(edges_copy, self.edges.items);

            const sortFn = struct {
                fn lessThan(_: void, a: Edge, b: Edge) bool {
                    return a.weight < b.weight;
                }
            }.lessThan;
            std.sort.block(Edge, edges_copy, {}, sortFn);

            // Disjoint set
            var parent = std.AutoHashMap(usize, usize).init(self.allocator);
            defer parent.deinit();
            
            for (edges_copy) |e| {
                if (!parent.contains(e.u)) try parent.put(e.u, e.u);
                if (!parent.contains(e.v)) try parent.put(e.v, e.v);
            }

            for (edges_copy) |e| {
                const u_root = try find(&parent, e.u);
                const v_root = try find(&parent, e.v);

                if (u_root != v_root) {
                    try result.append(self.allocator, e);
                    try parent.put(u_root, v_root);
                }
            }
            return result;
        }

        fn find(parent: *std.AutoHashMap(usize, usize), i: usize) !usize {
            var curr = i;
            while (curr != parent.get(curr).?) {
                curr = parent.get(curr).?;
            }
            return curr;
        }
    };
}