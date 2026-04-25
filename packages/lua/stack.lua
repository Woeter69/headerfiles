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

function stack.IsValidParentheses(s)
    local st = stack.New()
    local pairs = { [')'] = '(', ['}'] = '{', [']'] = '[' }
    for i = 1, #s do
        local char = s:sub(i, i)
        if char == '(' or char == '{' or char == '[' then
            st:Push(char)
        elseif pairs[char] then
            if st:IsEmpty() or st:Pop() ~= pairs[char] then
                return false
            end
        end
    end
    return st:IsEmpty()
end

return stack