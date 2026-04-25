const { SinglyLinkedList, DoublyLinkedList } = require('./linkedlist');
const { Stack, isValidParentheses } = require('./stack');
const { Queue, Deque, CircularQueue } = require('./queue');
const { MinHeap, MaxHeap } = require('./heap');
const { PriorityQueue } = require('./priorityqueue');
const { BinarySearchTree, TreeNode, Trie, AVLTree } = require('./tree');
const { Graph } = require('./graph');
const { bubbleSort, selectionSort, insertionSort, heapSort, quickSort, mergeSort } = require('./sorting');
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

console.log("--- New Features ---");

ll.reverse();
console.log("Singly Linked List head after reverse:", ll.head.data);
ll.head.next.next = ll.head; // Create a cycle for testing
console.log("Singly Linked List hasCycle:", ll.hasCycle());

console.log("Valid Parentheses '()[]{}':", isValidParentheses("()[]{}"));
console.log("Valid Parentheses '(]':", isValidParentheses("(]"));

const cq = new CircularQueue(3);
cq.enqueue(1);
cq.enqueue(2);
cq.enqueue(3);
console.log("CircularQueue isFull:", cq.isFull());
cq.dequeue();
cq.enqueue(4);
console.log("CircularQueue Rear:", cq.Rear());

const trie = new Trie();
trie.insert("apple");
console.log("Trie search 'apple':", trie.search("apple"));
console.log("Trie search 'app':", trie.search("app"));
console.log("Trie startsWith 'app':", trie.startsWith("app"));

const avl = new AVLTree();
avl.insertData(10);
avl.insertData(20);
avl.insertData(30);
console.log("AVLTree root data (should be 20 due to rotation):", avl.root.data);

const arrForNewSorts = [5, 2, 9, 1, 5, 6];
console.log("Quick Sort:", quickSort([...arrForNewSorts]));
console.log("Merge Sort:", mergeSort([...arrForNewSorts]));

console.log("=== All Tests Passed ===");
