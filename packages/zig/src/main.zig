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

    // Linked List Extended
    ll.reverse();
    std.debug.print("LinkedList reversed. Head: {d}\n", .{ll.head.?.data});
    const has_cycle = ll.hasCycle();
    std.debug.print("LinkedList has cycle: {}\n", .{has_cycle});

    // Valid Parentheses
    const is_valid = try stack.isValidParentheses(allocator, "({[]})");
    std.debug.print("isValidParentheses for '({{[]}})': {}\n", .{is_valid});

    // Circular Queue
    var cq = try queue.CircularQueue(i32).init(allocator, 3);
    defer cq.deinit();
    _ = cq.enqueue(1);
    _ = cq.enqueue(2);
    _ = cq.enqueue(3);
    const is_full = cq.isFull();
    const deq_val = cq.dequeue();
    std.debug.print("CircularQueue is_full: {}, dequeued: {?d}\n", .{is_full, deq_val});

    // Trie
    var t = try tree.Trie.init(allocator);
    try t.insert("hello");
    const found_hello = t.search("hello");
    const found_hell = t.search("hell");
    std.debug.print("Trie search 'hello': {}, search 'hell': {}\n", .{found_hello, found_hell});

    // AVL Tree
    var avl = tree.AVLTree(i32).init(allocator);
    try avl.insert(10);
    try avl.insert(20);
    try avl.insert(30); // Should trigger rotation
    std.debug.print("AVLTree root after inserts: {d}\n", .{avl.root.?.data});

    // QuickSort & MergeSort
    var q_arr = [_]i32{ 10, 7, 8, 9, 1, 5 };
    sorting.quickSort(i32, &q_arr);
    std.debug.print("QuickSorted array: {any}\n", .{q_arr});

    var m_arr = [_]i32{ 38, 27, 43, 3, 9, 82, 10 };
    try sorting.mergeSort(i32, &m_arr, allocator);
    std.debug.print("MergeSorted array: {any}\n", .{m_arr});

    std.debug.print("All tests completed.\n", .{});
}