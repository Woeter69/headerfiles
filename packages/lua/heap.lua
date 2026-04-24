local heap = {}

local Heap = {}
Heap.__index = Heap

function heap.New(less_func)
    return setmetatable({elements = {}, less = less_func}, Heap)
end

function Heap:Push(value)
    table.insert(self.elements, value)
    self:up(#self.elements)
end

function Heap:Pop()
    if #self.elements == 0 then return nil, false end
    local n = #self.elements
    self:swap(1, n)
    local val = table.remove(self.elements)
    if n > 1 then
        self:down(1, n - 1)
    end
    return val, true
end

function Heap:Peek()
    if #self.elements == 0 then return nil, false end
    return self.elements[1], true
end

function Heap:up(j)
    while true do
        local i = math.floor(j / 2) -- parent
        if i == 0 or not self.less(self.elements[j], self.elements[i]) then
            break
        end
        self:swap(i, j)
        j = i
    end
end

function Heap:down(i0, n)
    local i = i0
    while true do
        local j1 = 2 * i -- left child
        if j1 > n then break end
        local j = j1
        local j2 = j1 + 1 -- right child
        if j2 <= n and self.less(self.elements[j2], self.elements[j1]) then
            j = j2
        end
        if not self.less(self.elements[j], self.elements[i]) then
            break
        end
        self:swap(i, j)
        i = j
    end
end

function Heap:swap(i, j)
    self.elements[i], self.elements[j] = self.elements[j], self.elements[i]
end

function Heap:Size()
    return #self.elements
end

return heap