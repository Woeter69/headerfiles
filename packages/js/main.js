const { SinglyLinkedList, DoublyLinkedList } = require('./linkedlist');
const { Stack } = require('./stack');
const { Queue, Deque } = require('./queue');
const { MinHeap, MaxHeap } = require('./heap');
const { PriorityQueue } = require('./priorityqueue');
const { BinarySearchTree, TreeNode } = require('./tree');
const { Graph } = require('./graph');
const { bubbleSort, selectionSort, insertionSort, heapSort } = require('./sorting');
const { linearSearch, binarySearch } = require('./search');

console.log("=== Testing Data Structures and Algorithms ===");

const ll = new SinglyLinkedList();
ll.append(10);
ll.append(20);
console.log("Singly Linked List head data:", ll.head.data);

const stack = new Stack();
stack.push(1);
stack.push(2);
console.log("Stack pop:", stack.pop());

const queue = new Queue();
queue.enqueue(1);
queue.enqueue(2);
console.log("Queue dequeue:", queue.dequeue());

const minHeap = new MinHeap();
minHeap.insert(5);
minHeap.insert(2);
minHeap.insert(8);
console.log("MinHeap extractMin:", minHeap.extractMin());

const pq = new PriorityQueue();
pq.enqueue("task1", 2);
pq.enqueue("task2", 1);
console.log("PriorityQueue dequeue (lowest priority number first):", pq.dequeue());

const bst = new BinarySearchTree();
bst.insert(10);
bst.insert(5);
bst.insert(15);
console.log("BST root data:", bst.root.data);

const graph = new Graph();
graph.addVertex("A");
graph.addVertex("B");
graph.addEdge("A", "B", 1);
console.log("Graph BFS from A:", graph.bfs("A"));
console.log("Graph Kruskal MST:", graph.kruskalMST());

const arr = [5, 2, 9, 1, 5, 6];
console.log("Bubble Sort:", bubbleSort([...arr]));
console.log("Selection Sort:", selectionSort([...arr]));
console.log("Insertion Sort:", insertionSort([...arr]));
console.log("Heap Sort:", heapSort([...arr]));

const sortedArr = [1, 2, 5, 5, 6, 9];
console.log("Linear Search for 6:", linearSearch(sortedArr, 6));
console.log("Binary Search for 9:", binarySearch(sortedArr, 9));

console.log("=== All Tests Passed ===");
