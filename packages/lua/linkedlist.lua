local linkedlist = {}

-- --- Singly Linked List ---
local LinkedList = {}
LinkedList.__index = LinkedList

function linkedlist.LinkedList()
    return setmetatable({head = nil, tail = nil, size = 0}, LinkedList)
end

function LinkedList:AddAtEnd(value)
    local newNode = {value = value, next = nil}
    if self.head == nil then
        self.head = newNode
        self.tail = newNode
    else
        self.tail.next = newNode
        self.tail = newNode
    end
    self.size = self.size + 1
end

function LinkedList:AddAtStart(value)
    local newNode = {value = value, next = self.head}
    self.head = newNode
    if self.tail == nil then
        self.tail = newNode
    end
    self.size = self.size + 1
end

function LinkedList:RemoveFromStart()
    if self.head == nil then return nil, "list is empty" end
    local val = self.head.value
    self.head = self.head.next
    if self.head == nil then self.tail = nil end
    self.size = self.size - 1
    return val
end

function LinkedList:RemoveFromEnd()
    if self.head == nil then return nil, "list is empty" end
    if self.head == self.tail then
        local val = self.head.value
        self.head = nil
        self.tail = nil
        self.size = self.size - 1
        return val
    end
    local curr = self.head
    while curr.next ~= self.tail do
        curr = curr.next
    end
    local val = self.tail.value
    curr.next = nil
    self.tail = curr
    self.size = self.size - 1
    return val
end

function LinkedList:RemoveAt(index)
    if index < 1 or index > self.size then return nil, "index out of bounds" end
    if index == 1 then return self:RemoveFromStart() end
    if index == self.size then return self:RemoveFromEnd() end
    
    local curr = self.head
    for i = 1, index - 2 do
        curr = curr.next
    end
    local val = curr.next.value
    curr.next = curr.next.next
    self.size = self.size - 1
    return val
end

function LinkedList:Get(index)
    if index < 1 or index > self.size then return nil, "index out of bounds" end
    local curr = self.head
    for i = 1, index - 1 do
        curr = curr.next
    end
    return curr.value
end

function LinkedList:Reverse()
    local prev = nil
    local curr = self.head
    self.tail = self.head
    while curr ~= nil do
        local nextTemp = curr.next
        curr.next = prev
        prev = curr
        curr = nextTemp
    end
    self.head = prev
end

function LinkedList:HasCycle()
    local slow = self.head
    local fast = self.head
    while fast ~= nil and fast.next ~= nil do
        slow = slow.next
        fast = fast.next.next
        if slow == fast then return true end
    end
    return false
end

-- --- Doubly Linked List ---
local DoublyLinkedList = {}
DoublyLinkedList.__index = DoublyLinkedList

function linkedlist.DoublyLinkedList()
    return setmetatable({head = nil, tail = nil, size = 0}, DoublyLinkedList)
end

function DoublyLinkedList:AddAtStart(value)
    local newNode = {value = value, next = self.head, prev = nil}
    if self.head ~= nil then
        self.head.prev = newNode
    end
    self.head = newNode
    if self.tail == nil then
        self.tail = newNode
    end
    self.size = self.size + 1
end

function DoublyLinkedList:AddAtEnd(value)
    local newNode = {value = value, next = nil, prev = self.tail}
    if self.tail ~= nil then
        self.tail.next = newNode
    end
    self.tail = newNode
    if self.head == nil then
        self.head = newNode
    end
    self.size = self.size + 1
end

function DoublyLinkedList:RemoveFromStart()
    if self.head == nil then return nil, "list is empty" end
    local val = self.head.value
    self.head = self.head.next
    if self.head ~= nil then
        self.head.prev = nil
    else
        self.tail = nil
    end
    self.size = self.size - 1
    return val
end

function DoublyLinkedList:RemoveFromEnd()
    if self.tail == nil then return nil, "list is empty" end
    local val = self.tail.value
    self.tail = self.tail.prev
    if self.tail ~= nil then
        self.tail.next = nil
    else
        self.head = nil
    end
    self.size = self.size - 1
    return val
end

function DoublyLinkedList:RemoveAt(index)
    if index < 1 or index > self.size then return nil, "index out of bounds" end
    if index == 1 then return self:RemoveFromStart() end
    if index == self.size then return self:RemoveFromEnd() end
    
    local curr = self.head
    for i = 1, index - 1 do
        curr = curr.next
    end
    curr.prev.next = curr.next
    curr.next.prev = curr.prev
    self.size = self.size - 1
    return curr.value
end

return linkedlist