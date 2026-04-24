const std = @import("std");

const linkedlist = @import("linkedlist.zig");
const stack = @import("stack.zig");
const queue = @import("queue.zig");
const heap = @import("heap.zig");
const priorityqueue = @import("priorityqueue.zig");
const tree = @import("tree.zig");
const graph = @import("graph.zig");
const sorting = @import("sorting.zig");
const search = @import("search.zig");

fn minInt(a: i32, b: i32) bool {
    return a < b;
}

pub fn main() !void {
    var arena = std.heap.ArenaAllocator.init(std.heap.page_allocator);
    defer arena.deinit();
    const allocator = arena.allocator();

    std.debug.print("--- Testing Data Structures and Algorithms ---\n", .{});

    // Linked List
    var ll = linkedlist.SinglyLinkedList(i32).init(allocator);
    try ll.append(10);
    try ll.append(20);
    std.debug.print("LinkedList appended 10, 20. Head: {d}\n", .{ll.head.?.data});

    // Stack
    var s = stack.Stack(i32).init(allocator);
    try s.push(1);
    try s.push(2);
    std.debug.print("Stack popped: {?d}\n", .{s.pop()});

    // Queue
    var q = queue.Queue(i32).init(allocator);
    try q.enqueue(100);
    try q.enqueue(200);
    std.debug.print("Queue dequeued: {?d}\n", .{q.dequeue()});

    // Deque
    var dq = queue.Deque(i32).init(allocator);
    try dq.pushBack(1);
    try dq.pushFront(2);
    std.debug.print("Deque popFront: {?d}\n", .{dq.popFront()});

    // Heap
    var h = heap.Heap(i32, minInt).init(allocator);
    try h.insert(5);
    try h.insert(3);
    try h.insert(7);
    std.debug.print("Heap extracted (min): {?d}\n", .{h.extract()});

    // PriorityQueue
    var pq = priorityqueue.PriorityQueue(i32, minInt).init(allocator);
    try pq.enqueue(10);
    try pq.enqueue(2);
    std.debug.print("PriorityQueue extracted: {?d}\n", .{pq.dequeue()});

    // Tree (BST)
    var bst = tree.BST(i32).init(allocator);
    try bst.insert(50);
    try bst.insert(30);
    std.debug.print("BST root: {d}\n", .{bst.root.?.data});

    // Graph
    var g = graph.Graph().init(allocator);
    try g.addEdge(0, 1, 10);
    try g.addEdge(1, 2, 5);
    try g.addEdge(0, 2, 1);
    const mst = try g.kruskalMST();
    std.debug.print("Kruskal MST edges count: {d}\n", .{mst.items.len});

    // Sorting
    var arr = [_]i32{ 5, 2, 9, 1, 5, 6 };
    sorting.bubbleSort(i32, &arr);
    std.debug.print("BubbleSorted array: {any}\n", .{arr});

    var arr2 = [_]i32{ 5, 2, 9, 1, 5, 6 };
    sorting.heapSort(i32, &arr2);
    std.debug.print("HeapSorted array: {any}\n", .{arr2});

    // Search
    const search_idx = search.binarySearch(i32, &arr, 9);
    std.debug.print("BinarySearch for 9 found at index: {any}\n", .{search_idx});

    std.debug.print("All tests completed.\n", .{});
}