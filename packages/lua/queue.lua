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

return queue