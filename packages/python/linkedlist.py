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
