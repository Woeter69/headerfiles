using System;
using System.Collections.Generic;
using csharp_packages;

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Testing Data Structures and Algorithms");

        // Linked List
        var sll = new SinglyLinkedList<int>();
        sll.Add(1);
        sll.Add(2);
        Console.WriteLine($"Singly Linked List Head: {sll.Head?.Data}");

        var dll = new DoublyLinkedList<int>();
        dll.Add(10);
        dll.Add(20);
        Console.WriteLine($"Doubly Linked List Head: {dll.Head?.Data}");

        // Stack
        var stack = new MyStack<int>();
        stack.Push(1);
        stack.Push(2);
        Console.WriteLine($"Stack Pop: {stack.Pop()}");

        // Queue
        var queue = new MyQueue<int>();
        queue.Enqueue(1);
        queue.Enqueue(2);
        Console.WriteLine($"Queue Dequeue: {queue.Dequeue()}");

        var deque = new MyDeque<int>();
        deque.AddFirst(1);
        deque.AddLast(2);
        Console.WriteLine($"Deque RemoveLast: {deque.RemoveLast()}");

        // Heap
        var minHeap = new MinHeap<int>();
        minHeap.Insert(5);
        minHeap.Insert(3);
        Console.WriteLine($"MinHeap ExtractMin: {minHeap.ExtractMin()}");

        var maxHeap = new MaxHeap<int>();
        maxHeap.Insert(5);
        maxHeap.Insert(10);
        Console.WriteLine($"MaxHeap ExtractMax: {maxHeap.ExtractMax()}");

        // PriorityQueue
        var pq = new MyPriorityQueue<int>();
        pq.Enqueue(10);
        pq.Enqueue(5);
        Console.WriteLine($"PriorityQueue Dequeue (Min): {pq.Dequeue()}");

        // Tree
        var bst = new BST<int>();
        bst.Insert(10);
        bst.Insert(5);
        Console.WriteLine($"BST Root: {bst.Root?.Data}");

        var naryTree = new NaryTree<int>();
        naryTree.Root = new NaryTreeNode<int>(1);
        Console.WriteLine($"N-ary Tree Root: {naryTree.Root?.Data}");

        // Graph
        var graph = new Graph();
        graph.AddEdge(0, 1);
        graph.AddEdge(0, 2);
        var bfsRes = graph.BFS(0);
        Console.WriteLine($"Graph BFS: {string.Join(", ", bfsRes)}");
        
        var dfsRes = graph.DFS(0);
        Console.WriteLine($"Graph DFS: {string.Join(", ", dfsRes)}");

        // Kruskal
        var edges = new List<Edge> {
            new Edge(0, 1, 10),
            new Edge(0, 2, 6),
            new Edge(1, 2, 5)
        };
        var mst = KruskalMST.FindMST(edges, 3);
        Console.WriteLine($"Kruskal MST Edges count: {mst.Count}");

        // Sorting
        int[] arr = { 4, 2, 7, 1, 3 };
        Sorting.BubbleSort(arr);
        Console.WriteLine($"Bubble Sort: {string.Join(", ", arr)}");

        arr = new[] { 4, 2, 7, 1, 3 };
        Sorting.SelectionSort(arr);
        Console.WriteLine($"Selection Sort: {string.Join(", ", arr)}");

        arr = new[] { 4, 2, 7, 1, 3 };
        Sorting.InsertionSort(arr);
        Console.WriteLine($"Insertion Sort: {string.Join(", ", arr)}");

        arr = new[] { 4, 2, 7, 1, 3 };
        Sorting.HeapSort(arr);
        Console.WriteLine($"Heap Sort: {string.Join(", ", arr)}");

        arr = new[] { 4, 2, 7, 1, 3 };
        Sorting.QuickSort(arr);
        Console.WriteLine($"Quick Sort: {string.Join(", ", arr)}");

        arr = new[] { 4, 2, 7, 1, 3 };
        Sorting.MergeSort(arr);
        Console.WriteLine($"Merge Sort: {string.Join(", ", arr)}");

        // Search
        int[] sortedArr = { 1, 2, 3, 4, 7 };
        Console.WriteLine($"Linear Search for 3: Index {Searching.LinearSearch(sortedArr, 3)}");
        Console.WriteLine($"Binary Search for 4: Index {Searching.BinarySearch(sortedArr, 4)}");

        // Linked List New Features
        var sllTest = new SinglyLinkedList<int>();
        sllTest.Add(1);
        sllTest.Add(2);
        sllTest.Add(3);
        sllTest.Reverse();
        Console.WriteLine($"Reversed SLL Head: {sllTest.Head?.Data}");
        Console.WriteLine($"Has Cycle SLL: {sllTest.HasCycle()}");

        // Stack Utilities
        Console.WriteLine($"IsValidParentheses '()[]{{}}': {StackUtilities.IsValidParentheses("()[]{}")}");

        // CircularQueue
        var cq = new CircularQueue<int>(3);
        cq.Enqueue(1);
        cq.Enqueue(2);
        cq.Enqueue(3);
        Console.WriteLine($"CircularQueue Dequeue: {cq.Dequeue()}");

        // Trie
        var trie = new Trie();
        trie.Insert("apple");
        Console.WriteLine($"Trie Search 'apple': {trie.Search("apple")}");
        Console.WriteLine($"Trie StartsWith 'app': {trie.StartsWith("app")}");

        // AVL Tree
        var avl = new AVLTree<int>();
        avl.Insert(10);
        avl.Insert(20);
        avl.Insert(30);
        Console.WriteLine($"AVL Root after 10,20,30: {avl.Root?.Data}");
    }
}