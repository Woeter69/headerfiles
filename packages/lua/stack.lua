local stack = {}

local Stack = {}
Stack.__index = Stack

function stack.New()
    return setmetatable({elements = {}}, Stack)
end

function Stack:Push(value)
    table.insert(self.elements, value)
end

function Stack:Pop()
    if self:IsEmpty() then return nil, "stack is empty" end
    return table.remove(self.elements)
end

function Stack:Peek()
    if self:IsEmpty() then return nil, "stack is empty" end
    return self.elements[#self.elements]
end

function Stack:IsEmpty()
    return #self.elements == 0
end

function Stack:Size()
    return #self.elements
end

return stack