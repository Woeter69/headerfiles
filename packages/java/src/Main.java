import dsalgo.*;

import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        System.out.println("--- Singly Linked List ---");
        SLinkedList<Integer> sll = new SLinkedList<>();
        sll.add(1); sll.add(2); sll.add(3);
        sll.printList();

        System.out.println("\n--- Doubly Linked List ---");
        DLinkedList<Integer> dll = new DLinkedList<>();
        dll.add(4); dll.add(5); dll.add(6);
        dll.printList();

        System.out.println("\n--- Stack ---");
        MyStack<Integer> stack = new MyStack<>();
        stack.push(10); stack.push(20);
        System.out.println("Popped: " + stack.pop());

        System.out.println("\n--- Queue ---");
        MyQueue<Integer> queue = new MyQueue<>();
        queue.enqueue(30); queue.enqueue(40);
        System.out.println("Dequeued: " + queue.dequeue());

        System.out.println("\n--- Deque ---");
        MyDeque<Integer> deque = new MyDeque<>();
        deque.addFirst(1); deque.addLast(2);
        System.out.println("Removed First: " + deque.removeFirst());

        System.out.println("\n--- Heap (Min Heap) ---");
        MyHeap<Integer> minHeap = new MyHeap<>(true);
        minHeap.insert(5); minHeap.insert(2); minHeap.insert(8);
        System.out.println("Extracted Min: " + minHeap.extractTop());

        System.out.println("\n--- Priority Queue ---");
        MyPriorityQueue<Integer> pq = new MyPriorityQueue<>();
        pq.enqueue(15); pq.enqueue(10);
        System.out.println("Dequeued (Min): " + pq.dequeue());

        System.out.println("\n--- BST ---");
        BST<Integer> bst = new BST<>();
        bst.insert(50); bst.insert(30); bst.insert(70);
        System.out.print("Inorder: "); bst.inorder();
        System.out.println("Search 30: " + bst.search(30));

        System.out.println("\n--- N-ary Tree ---");
        NaryTree<String> nary = new NaryTree<>("Root");
        nary.addChild(nary.getRoot(), "Child1");
        nary.addChild(nary.getRoot(), "Child2");
        nary.printTree(nary.getRoot(), "");

        System.out.println("\n--- Graph ---");
        Graph g = new Graph(4);
        g.addEdge(0, 1, 10);
        g.addEdge(0, 2, 6);
        g.addEdge(0, 3, 5);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 4);
        g.bfs(0);
        g.dfs(0);
        g.kruskalMST();

        System.out.println("\n--- Sorting ---");
        int[] arr = {64, 25, 12, 22, 11};
        Sorting.bubbleSort(arr);
        System.out.println("Bubble Sort: " + Arrays.toString(arr));
        
        int[] arr2 = {64, 25, 12, 22, 11};
        Sorting.selectionSort(arr2);
        System.out.println("Selection Sort: " + Arrays.toString(arr2));

        int[] arr3 = {64, 25, 12, 22, 11};
        Sorting.insertionSort(arr3);
        System.out.println("Insertion Sort: " + Arrays.toString(arr3));

        int[] arr4 = {64, 25, 12, 22, 11};
        Sorting.heapSort(arr4);
        System.out.println("Heap Sort: " + Arrays.toString(arr4));

        System.out.println("\n--- Search ---");
        int[] sortedArr = {11, 12, 22, 25, 64};
        System.out.println("Linear Search 22 at index: " + Search.linearSearch(sortedArr, 22));
        System.out.println("Binary Search 25 at index: " + Search.binarySearch(sortedArr, 25));
    }
}
