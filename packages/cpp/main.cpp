#include <iostream>
#include <vector>
#include <string>
#include "LinkedList.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "Heap.hpp"
#include "PriorityQueue.hpp"
#include "Tree.hpp"
#include "Graph.hpp"
#include "Sorting.hpp"
#include "Search.hpp"

int main() {
    std::cout << "--- Testing LinkedList ---\n";
    LinkedList ll;
    ll.insert(1);
    ll.insert(2);
    ll.insert(3);
    std::cout << "Original: "; ll.print();
    ll.reverse();
    std::cout << "Reversed: "; ll.print();
    std::cout << "Has Cycle: " << (ll.hasCycle() ? "Yes" : "No") << "\n";

    std::cout << "--- Testing DoublyLinkedList ---\n";
    DoublyLinkedList dll;
    dll.insert(1);
    dll.insert(2);
    dll.print();

    std::cout << "--- Testing Stack ---\n";
    Stack s;
    s.push(1);
    s.push(2);
    std::cout << "Top: " << s.top() << "\n";
    std::string parens = "{[()]}";
    std::cout << "Valid Parentheses '" << parens << "': " << (isValidParentheses(parens) ? "Yes" : "No") << "\n";
    std::string bad_parens = "{[(])}";
    std::cout << "Valid Parentheses '" << bad_parens << "': " << (isValidParentheses(bad_parens) ? "Yes" : "No") << "\n";

    std::cout << "--- Testing Queue ---\n";
    Queue q;
    q.push(1);
    q.push(2);
    std::cout << "Front: " << q.front() << "\n";

    std::cout << "--- Testing Deque ---\n";
    Deque dq;
    dq.push_front(1);
    dq.push_back(2);
    std::cout << "Back: " << dq.back() << "\n";

    std::cout << "--- Testing CircularQueue ---\n";
    CircularQueue cq(3);
    cq.enQueue(1);
    cq.enQueue(2);
    cq.enQueue(3);
    std::cout << "Is Full: " << (cq.isFull() ? "Yes" : "No") << "\n";
    cq.deQueue();
    cq.enQueue(4);
    std::cout << "Rear: " << cq.Rear() << "\n";

    std::cout << "--- Testing Heap ---\n";
    Heap minH;
    minH.push(5);
    minH.push(2);
    std::cout << "Min: " << minH.top() << "\n";
    
    std::cout << "--- Testing PriorityQueue ---\n";
    PriorityQueue pq;
    pq.push(5);
    pq.push(10);
    std::cout << "Max: " << pq.top() << "\n";

    std::cout << "--- Testing BST ---\n";
    BST bst;
    bst.insert(2);
    bst.insert(1);
    bst.insert(3);
    bst.print();

    std::cout << "--- Testing Trie ---\n";
    Trie trie;
    trie.insert("hello");
    std::cout << "Search 'hello': " << (trie.search("hello") ? "Yes" : "No") << "\n";
    std::cout << "StartsWith 'hel': " << (trie.startsWith("hel") ? "Yes" : "No") << "\n";
    std::cout << "Search 'world': " << (trie.search("world") ? "Yes" : "No") << "\n";

    std::cout << "--- Testing AVLTree ---\n";
    AVLTree avl;
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);
    avl.print();

    std::cout << "--- Testing Graph ---\n";
    Graph g;
    g.addEdge(0, 1, 10);
    g.addEdge(1, 2, 5);
    g.addEdge(0, 2, 6);
    std::cout << "BFS: "; g.BFS(0);
    std::cout << "DFS: "; g.DFS(0);
    std::cout << "Kruskal MST Weight: " << g.KruskalMST() << "\n";

    std::cout << "--- Testing Sorting & Search ---\n";
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    Sorting::heapSort(arr);
    std::cout << "HeapSort: ";
    for (int x : arr) std::cout << x << " ";
    std::cout << "\n";

    std::vector<int> arr2 = {10, 7, 8, 9, 1, 5};
    Sorting::quickSort(arr2);
    std::cout << "QuickSort: ";
    for (int x : arr2) std::cout << x << " ";
    std::cout << "\n";

    std::vector<int> arr3 = {12, 11, 13, 5, 6, 7};
    Sorting::mergeSort(arr3);
    std::cout << "MergeSort: ";
    for (int x : arr3) std::cout << x << " ";
    std::cout << "\n";

    std::cout << "Binary Search for 5 in HeapSort array: " << Search::binarySearch(arr, 5) << "\n";
    
    return 0;
}
