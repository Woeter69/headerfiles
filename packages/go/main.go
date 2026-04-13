package main

import (
	"fmt"

	"github.com/Woeter69/headerfiles/packages/graph"
	"github.com/Woeter69/headerfiles/packages/heap"
	"github.com/Woeter69/headerfiles/packages/linkedlist"
	"github.com/Woeter69/headerfiles/packages/priorityqueue"
	"github.com/Woeter69/headerfiles/packages/queue"
	"github.com/Woeter69/headerfiles/packages/search"
	"github.com/Woeter69/headerfiles/packages/sorting"
	"github.com/Woeter69/headerfiles/packages/stack"
	"github.com/Woeter69/headerfiles/packages/tree"
)

// main is the entry point demonstrating how to import and use all the
// custom data structure and algorithm packages implemented in this repository.
func main() {
	fmt.Println("=== Linked List ===")
	ll := &linkedlist.LinkedList[int]{}
	ll.AddAtEnd(10)
	ll.AddAtStart(5)
	ll.AddAtEnd(20)
	val, _ := ll.RemoveFromStart()
	fmt.Printf("Removed from start: %d, Current Size: %d\n", val, ll.Size)

	fmt.Println("\n=== Doubly Linked List ===")
	dll := &linkedlist.DoublyLinkedList[string]{}
	dll.AddAtStart("World")
	dll.AddAtStart("Hello")
	dll.AddAtEnd("!")
	dVal, _ := dll.RemoveFromEnd()
	fmt.Printf("Removed from end: %s, Current Size: %d\n", dVal, dll.Size)

	fmt.Println("\n=== Stack ===")
	s := stack.New[int]()
	s.Push(100)
	s.Push(200)
	sVal, _ := s.Pop()
	fmt.Printf("Popped: %d, IsEmpty: %t\n", sVal, s.IsEmpty())

	fmt.Println("\n=== Queue ===")
	q := queue.New[string]()
	q.Enqueue("First")
	q.Enqueue("Second")
	qVal, _ := q.Dequeue()
	fmt.Printf("Dequeued: %s, IsEmpty: %t\n", qVal, q.IsEmpty())

	fmt.Println("\n=== Tree (BST) ===")
	// Create a BST comparing integers
	bst := tree.NewBST[int](func(a, b int) bool { return a < b })
	bst.Insert(10)
	bst.Insert(5)
	bst.Insert(15)
	fmt.Printf("BST contains 5? %t\n", bst.Search(5))
	fmt.Printf("BST contains 20? %t\n", bst.Search(20))

	fmt.Println("\n=== Heap ===")
	// Min-heap
	minHeap := heap.New[int](func(a, b int) bool { return a < b })
	minHeap.Push(50)
	minHeap.Push(10)
	minHeap.Push(30)
	hVal, _ := minHeap.Pop()
	fmt.Printf("Popped from Min-Heap: %d\n", hVal)

	fmt.Println("\n=== Priority Queue ===")
	// Max Priority Queue
	pq := priorityqueue.NewMaxPQ[string]()
	pq.Push("Low Priority", 1)
	pq.Push("High Priority", 10)
	pq.Push("Medium Priority", 5)
	pqVal, _ := pq.Pop()
	fmt.Printf("Popped highest priority task: %s\n", pqVal)

	fmt.Println("\n=== Graph ===")
	g := graph.New[int]()
	g.AddUndirectedEdge(1, 2)
	g.AddUndirectedEdge(1, 3)
	g.AddUndirectedEdge(2, 4)
	fmt.Print("BFS Traversal from 1: ")
	g.BFS(1, func(v int) { fmt.Printf("%d ", v) })
	fmt.Println()

	fmt.Print("DFS Traversal from 1: ")
	g.DFS(1, func(v int) { fmt.Printf("%d ", v) })
	fmt.Println()

	fmt.Println("\n=== Minimum Spanning Tree (Kruskal) ===")
	vertices := []string{"A", "B", "C", "D"}
	edges := []graph.Edge[string]{
		{U: "A", V: "B", Weight: 1},
		{U: "B", V: "C", Weight: 2},
		{U: "A", V: "C", Weight: 3},
		{U: "C", V: "D", Weight: 1},
	}
	mst := graph.KruskalMST(vertices, edges)
	fmt.Printf("MST Edges: %+v\n", mst)

	fmt.Println("\n=== Sorting ===")
	arr := []int{9, 4, 7, 1, 5, 8, 3}
	fmt.Printf("Original Array: %v\n", arr)
	sorting.HeapSort(arr, func(a, b int) bool { return a < b })
	fmt.Printf("Heap Sorted Array: %v\n", arr)

	fmt.Println("\n=== Search ===")
	// arr is now sorted: [1, 3, 4, 5, 7, 8, 9]
	target := 5
	idx := search.BinarySearch(arr, target, func(a, b int) bool { return a < b })
	fmt.Printf("Binary Search index for %d: %d\n", target, idx)

	lIdx := search.LinearSearch(arr, 100)
	fmt.Printf("Linear Search index for 100 (not found): %d\n", lIdx)
}
