mod linkedlist;
mod stack;
mod queue;
mod heap;
mod priorityqueue;
mod tree;
mod graph;
mod sorting;
mod search;

use linkedlist::{SinglyLinkedList, DoublyLinkedList};
use stack::Stack;
use queue::{Queue, Deque};
use heap::{MinHeap, MaxHeap};
use priorityqueue::PriorityQueue;
use tree::{BST, NaryTree};
use graph::Graph;
use sorting::{bubble_sort, selection_sort, insertion_sort, heap_sort};
use search::{linear_search, binary_search};

fn main() {
    println!("Testing Data Structures and Algorithms in Rust!");

    let mut list = SinglyLinkedList::new();
    list.push_front(1);
    println!("SinglyLinkedList tested.");

    let mut dlist = DoublyLinkedList::new();
    dlist.push_back(2);
    println!("DoublyLinkedList tested.");

    let mut stack = Stack::new();
    stack.push(10);
    println!("Stack tested. popped: {:?}", stack.pop());

    let mut q = Queue::new();
    q.enqueue(5);
    println!("Queue tested. dequeued: {:?}", q.dequeue());

    let mut deque = Deque::new();
    deque.push_front(1);
    deque.push_back(2);
    println!("Deque tested. popped front: {:?}", deque.pop_front());

    let mut min_heap = MinHeap::new();
    min_heap.push(3);
    println!("MinHeap tested.");

    let mut max_heap = MaxHeap::new();
    max_heap.push(4);
    println!("MaxHeap tested.");

    let mut pq = PriorityQueue::new();
    pq.push("task 1", 10);
    pq.push("task 2", 20);
    println!("PriorityQueue tested. pop: {:?}", pq.pop());

    let mut bst = BST::new();
    bst.insert(5);
    bst.insert(2);
    println!("BST tested.");

    let _ntree: NaryTree<i32> = NaryTree::new();
    println!("NaryTree tested.");

    let mut g = Graph::new();
    g.add_edge(0, 1, 10);
    g.add_edge(1, 2, 5);
    g.add_edge(0, 2, 20);
    println!("Graph BFS: {:?}", g.bfs(0));
    println!("Graph DFS: {:?}", g.dfs(0));
    println!("Graph Kruskal MST: {:?}", g.kruskal_mst());

    let mut arr = [5, 3, 8, 4, 2];
    bubble_sort(&mut arr);
    println!("Bubble sort: {:?}", arr);
    
    let mut arr2 = [5, 3, 8, 4, 2];
    selection_sort(&mut arr2);
    println!("Selection sort: {:?}", arr2);

    let mut arr3 = [5, 3, 8, 4, 2];
    insertion_sort(&mut arr3);
    println!("Insertion sort: {:?}", arr3);

    let mut arr4 = [5, 3, 8, 4, 2];
    heap_sort(&mut arr4);
    println!("Heap sort: {:?}", arr4);

    let arr5 = [1, 2, 3, 4, 5];
    println!("Linear search for 3: {:?}", linear_search(&arr5, &3));
    println!("Binary search for 4: {:?}", binary_search(&arr5, &4));
}
