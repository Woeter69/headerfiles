from linkedlist import SinglyLinkedList, DoublyLinkedList
from stack import Stack, is_valid_parentheses
from queue import Queue, Deque, CircularQueue
from heap import MinHeap, MaxHeap
from priorityqueue import PriorityQueue
from tree import BST, NaryNode, Trie, AVLTree
from graph import Graph
from sorting import bubble_sort, selection_sort, insertion_sort, heap_sort, quick_sort, merge_sort
from search import linear_search, binary_search

def test_linkedlist():
    print("--- Testing LinkedList ---")
    sll = SinglyLinkedList()
    sll.insert(1)
    sll.insert(2)
    sll.insert(3)
    print("SinglyLinkedList:", sll.display())
    sll.reverse()
    print("SinglyLinkedList after reverse:", sll.display())
    print("SinglyLinkedList has_cycle:", sll.has_cycle())

    dll = DoublyLinkedList()
    dll.insert(10)
    dll.insert(20)
    print("DoublyLinkedList:", dll.display())

def test_stack():
    print("\n--- Testing Stack ---")
    s = Stack()
    s.push(1)
    s.push(2)
    print("Stack pop:", s.pop())
    print("Stack peek:", s.peek())
    print("Stack is_valid_parentheses '()[]{}':", is_valid_parentheses("()[]{}"))
    print("Stack is_valid_parentheses '(]':", is_valid_parentheses("(]"))

def test_queue():
    print("\n--- Testing Queue ---")
    q = Queue()
    q.enqueue(1)
    q.enqueue(2)
    print("Queue dequeue:", q.dequeue())
    
    dq = Deque()
    dq.add_rear(1)
    dq.add_front(2)
    print("Deque remove_rear:", dq.remove_rear())
    
    cq = CircularQueue(5)
    cq.enqueue(10)
    cq.enqueue(20)
    print("CircularQueue dequeue:", cq.dequeue())

def test_heap():
    print("\n--- Testing Heap ---")
    mh = MinHeap()
    mh.push(3)
    mh.push(1)
    mh.push(2)
    print("MinHeap pop:", mh.pop())
    
    mxh = MaxHeap()
    mxh.push(3)
    mxh.push(1)
    mxh.push(2)
    print("MaxHeap pop:", mxh.pop())

def test_priorityqueue():
    print("\n--- Testing PriorityQueue ---")
    pq = PriorityQueue()
    pq.put("task1", 2)
    pq.put("task2", 1)
    print("PriorityQueue get:", pq.get())

def test_tree():
    print("\n--- Testing Tree ---")
    bst = BST()
    bst.insert(5)
    bst.insert(3)
    bst.insert(7)
    print("BST inorder:", bst.inorder(bst.root, []))
    
    nary = NaryNode(1)
    nary.add_child(NaryNode(2))
    nary.add_child(NaryNode(3))
    print("Nary tree root children count:", len(nary.children))
    
    t = Trie()
    t.insert("apple")
    print("Trie search 'apple':", t.search("apple"))
    print("Trie startsWith 'app':", t.starts_with("app"))
    
    avl = AVLTree()
    root = None
    root = avl.insert(root, 10)
    root = avl.insert(root, 20)
    root = avl.insert(root, 30)
    print("AVL pre_order:", avl.pre_order(root))

def test_graph():
    print("\n--- Testing Graph ---")
    g = Graph()
    g.add_edge(1, 2, 10)
    g.add_edge(2, 3, 20)
    g.add_edge(1, 3, 5)
    print("Graph BFS:", g.bfs(1))
    print("Graph DFS:", g.dfs(1))
    print("Graph Kruskal MST:", g.kruskal_mst())

def test_sorting():
    print("\n--- Testing Sorting ---")
    arr = [3, 1, 4, 1, 5, 9, 2, 6]
    print("Bubble sort:", bubble_sort(arr.copy()))
    print("Selection sort:", selection_sort(arr.copy()))
    print("Insertion sort:", insertion_sort(arr.copy()))
    print("Heap sort:", heap_sort(arr.copy()))
    print("Quick sort:", quick_sort(arr.copy()))
    print("Merge sort:", merge_sort(arr.copy()))

def test_search():
    print("\n--- Testing Search ---")
    arr = [1, 2, 3, 4, 5, 6, 9]
    print("Linear search for 4:", linear_search(arr, 4))
    print("Binary search for 6:", binary_search(arr, 6))

if __name__ == "__main__":
    test_linkedlist()
    test_stack()
    test_queue()
    test_heap()
    test_priorityqueue()
    test_tree()
    test_graph()
    test_sorting()
    test_search()
    print("\nAll Python tests passed!")
