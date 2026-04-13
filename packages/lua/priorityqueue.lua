local priorityqueue = {}
local heap = require("heap")

local PriorityQueue = {}
PriorityQueue.__index = PriorityQueue

function priorityqueue.NewMinPQ()
    local pq = {
        h = heap.New(function(a, b) return a.priority < b.priority end)
    }
    return setmetatable(pq, PriorityQueue)
end

function priorityqueue.NewMaxPQ()
    local pq = {
        h = heap.New(function(a, b) return a.priority > b.priority end)
    }
    return setmetatable(pq, PriorityQueue)
end

function PriorityQueue:Push(value, priority)
    self.h:Push({value = value, priority = priority})
end

function PriorityQueue:Pop()
    local item, ok = self.h:Pop()
    if not ok then return nil, false end
    return item.value, true
end

function PriorityQueue:Peek()
    local item, ok = self.h:Peek()
    if not ok then return nil, false end
    return item.value, true
end

function PriorityQueue:Size()
    return self.h:Size()
end

return priorityqueue