local queue = {}

-- --- Queue ---
local Queue = {}
Queue.__index = Queue

function queue.New()
    return setmetatable({elements = {}}, Queue)
end

function Queue:Enqueue(value)
    table.insert(self.elements, value)
end

function Queue:Dequeue()
    if self:IsEmpty() then return nil, "queue is empty" end
    return table.remove(self.elements, 1)
end

function Queue:Peek()
    if self:IsEmpty() then return nil, "queue is empty" end
    return self.elements[1]
end

function Queue:IsEmpty()
    return #self.elements == 0
end

function Queue:Size()
    return #self.elements
end

-- --- Deque ---
local Deque = {}
Deque.__index = Deque

function queue.NewDeque()
    return setmetatable({elements = {}}, Deque)
end

function Deque:PushBack(value)
    table.insert(self.elements, value)
end

function Deque:PushFront(value)
    table.insert(self.elements, 1, value)
end

function Deque:PopBack()
    if #self.elements == 0 then return nil, "deque is empty" end
    return table.remove(self.elements)
end

function Deque:PopFront()
    if #self.elements == 0 then return nil, "deque is empty" end
    return table.remove(self.elements, 1)
end

-- --- Circular Queue ---
local CircularQueue = {}
CircularQueue.__index = CircularQueue

function queue.NewCircularQueue(capacity)
    return setmetatable({elements = {}, capacity = capacity, head = 1, tail = 1, size = 0}, CircularQueue)
end

function CircularQueue:Enqueue(value)
    if self:IsFull() then return false, "queue is full" end
    self.elements[self.tail] = value
    self.tail = (self.tail % self.capacity) + 1
    self.size = self.size + 1
    return true
end

function CircularQueue:Dequeue()
    if self:IsEmpty() then return nil, "queue is empty" end
    local val = self.elements[self.head]
    self.elements[self.head] = nil
    self.head = (self.head % self.capacity) + 1
    self.size = self.size - 1
    return val
end

function CircularQueue:IsEmpty()
    return self.size == 0
end

function CircularQueue:IsFull()
    return self.size == self.capacity
end

function CircularQueue:Peek()
    if self:IsEmpty() then return nil, "queue is empty" end
    return self.elements[self.head]
end

return queue