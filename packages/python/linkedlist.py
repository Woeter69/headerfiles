class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class SinglyLinkedList:
    def __init__(self):
        self.head = None
    
    def insert(self, data):
        if not self.head:
            self.head = Node(data)
        else:
            cur = self.head
            while cur.next:
                cur = cur.next
            cur.next = Node(data)
            
    def display(self):
        cur = self.head
        res = []
        while cur:
            res.append(cur.data)
            cur = cur.next
        return res

    def reverse(self):
        prev = None
        cur = self.head
        while cur:
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        self.head = prev

    def has_cycle(self):
        slow = self.head
        fast = self.head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                return True
        return False

class DNode:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class DoublyLinkedList:
    def __init__(self):
        self.head = None
        
    def insert(self, data):
        if not self.head:
            self.head = DNode(data)
        else:
            cur = self.head
            while cur.next:
                cur = cur.next
            new_node = DNode(data)
            cur.next = new_node
            new_node.prev = cur
            
    def display(self):
        cur = self.head
        res = []
        while cur:
            res.append(cur.data)
            cur = cur.next
        return res
