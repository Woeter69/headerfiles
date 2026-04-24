-- Configure package.path to resolve local imports cleanly
package.path = package.path .. ";./?.lua"

local linkedlist = require("linkedlist")
local stack = require("stack")
local queue = require("queue")
local heap = require("heap")
local priorityqueue = require("priorityqueue")
local tree = require("tree")
local graph = require("graph")
local sorting = require("sorting")
local search = require("search")

print("=== Linked List ===")
local ll = linkedlist.LinkedList()
ll:AddAtEnd(10)
ll:AddAtStart(5)
ll:AddAtEnd(20)
local val = ll:RemoveFromStart()
print(string.format("Removed from start: %d, Current Size: %d", val, ll.size))

print("\n=== Doubly Linked List ===")
local dll = linkedlist.DoublyLinkedList()
dll:AddAtStart("World")
dll:AddAtStart("Hello")
dll:AddAtEnd("!")
local dVal = dll:RemoveFromEnd()
print(string.format("Removed from end: %s, Current Size: %d", dVal, dll.size))

print("\n=== Stack ===")
local s = stack.New()
s:Push(100)
s:Push(200)
local sVal = s:Pop()
print(string.format("Popped: %d, IsEmpty: %s", sVal, tostring(s:IsEmpty())))

print("\n=== Queue ===")
local q = queue.New()
q:Enqueue("First")
q:Enqueue("Second")
local qVal = q:Dequeue()
print(string.format("Dequeued: %s, IsEmpty: %s", qVal, tostring(q:IsEmpty())))

print("\n=== Tree (BST) ===")
local bst = tree.NewBST(function(a, b) return a < b end)
bst:Insert(10)
bst:Insert(5)
bst:Insert(15)
print(string.format("BST contains 5? %s", tostring(bst:Search(5))))
print(string.format("BST contains 20? %s", tostring(bst:Search(20))))

print("\n=== Heap ===")
local minHeap = heap.New(function(a, b) return a < b end)
minHeap:Push(50)
minHeap:Push(10)
minHeap:Push(30)
local hVal = minHeap:Pop()
print(string.format("Popped from Min-Heap: %d", hVal))

print("\n=== Priority Queue ===")
local pq = priorityqueue.NewMaxPQ()
pq:Push("Low Priority", 1)
pq:Push("High Priority", 10)
pq:Push("Medium Priority", 5)
local pqVal = pq:Pop()
print(string.format("Popped highest priority task: %s", pqVal))

print("\n=== Graph ===")
local g = graph.New()
g:AddUndirectedEdge(1, 2)
g:AddUndirectedEdge(1, 3)
g:AddUndirectedEdge(2, 4)
io.write("BFS Traversal from 1: ")
g:BFS(1, function(v) io.write(v .. " ") end)
print()

io.write("DFS Traversal from 1: ")
g:DFS(1, function(v) io.write(v .. " ") end)
print()

print("\n=== Minimum Spanning Tree (Kruskal) ===")
local vertices = {"A", "B", "C", "D"}
local edges = {
    {u = "A", v = "B", weight = 1},
    {u = "B", v = "C", weight = 2},
    {u = "A", v = "C", weight = 3},
    {u = "C", v = "D", weight = 1}
}
local mst = graph.KruskalMST(vertices, edges)
io.write("MST Edges: ")
for _, edge in ipairs(mst) do
    io.write(string.format("{u=%s, v=%s, weight=%d} ", edge.u, edge.v, edge.weight))
end
print()

print("\n=== Sorting ===")
local arr = {9, 4, 7, 1, 5, 8, 3}
io.write("Original Array: ")
for _, v in ipairs(arr) do io.write(v .. " ") end
print()
sorting.HeapSort(arr, function(a, b) return a < b end)
io.write("Heap Sorted Array: ")
for _, v in ipairs(arr) do io.write(v .. " ") end
print()

print("\n=== Search ===")
local target = 5
local idx = search.BinarySearch(arr, target, function(a, b) return a < b end)
print(string.format("Binary Search index for %d: %d", target, idx))

local lIdx = search.LinearSearch(arr, 100)
print(string.format("Linear Search index for 100 (not found): %d", lIdx))