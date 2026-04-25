class Queue:
    def __init__(self):
        self.items = []
        
    def enqueue(self, item):
        self.items.append(item)
        
    def dequeue(self):
        if not self.is_empty():
            return self.items.pop(0)
        return None
        
    def is_empty(self):
        return len(self.items) == 0

class Deque:
    def __init__(self):
        self.items = []
        
    def add_front(self, item):
        self.items.insert(0, item)
        
    def add_rear(self, item):
        self.items.append(item)
        
    def remove_front(self):
        if not self.is_empty():
            return self.items.pop(0)
        return None
        
    def remove_rear(self):
        if not self.is_empty():
            return self.items.pop()
        return None
        
    def is_empty(self):
        return len(self.items) == 0

class CircularQueue:
    def __init__(self, k):
        self.k = k
        self.queue = [None] * k
        self.head = self.tail = -1

    def enqueue(self, data):
        if ((self.tail + 1) % self.k == self.head):
            return False
        elif (self.head == -1):
            self.head = 0
            self.tail = 0
            self.queue[self.tail] = data
        else:
            self.tail = (self.tail + 1) % self.k
            self.queue[self.tail] = data
        return True

    def dequeue(self):
        if (self.head == -1):
            return None
        elif (self.head == self.tail):
            temp = self.queue[self.head]
            self.head = -1
            self.tail = -1
            return temp
        else:
            temp = self.queue[self.head]
            self.head = (self.head + 1) % self.k
            return temp

    def is_empty(self):
        return self.head == -1
