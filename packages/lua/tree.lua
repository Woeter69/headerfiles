local tree = {}

-- --- Binary Search Tree ---
local BST = {}
BST.__index = BST

function tree.NewBST(less)
    return setmetatable({root = nil, less = less}, BST)
end

function BST:Insert(value)
    self.root = self:_insert(self.root, value)
end

function BST:_insert(node, value)
    if node == nil then
        return {value = value, left = nil, right = nil}
    end
    if self.less(value, node.value) then
        node.left = self:_insert(node.left, value)
    else
        node.right = self:_insert(node.right, value)
    end
    return node
end

function BST:Search(value)
    return self:_search(self.root, value)
end

function BST:_search(node, value)
    if node == nil then return false end
    if not self.less(value, node.value) and not self.less(node.value, value) then
        return true
    end
    if self.less(value, node.value) then
        return self:_search(node.left, value)
    end
    return self:_search(node.right, value)
end

-- --- General Tree ---
local GeneralTree = {}
GeneralTree.__index = GeneralTree

function tree.NewGeneralTree(rootValue)
    return setmetatable({
        root = {value = rootValue, children = {}}
    }, GeneralTree)
end

function GeneralTree:AddEdge(parentValue, childValue)
    local parent = self:Find(self.root, parentValue)
    if parent == nil then return false, "parent not found" end
    table.insert(parent.children, {value = childValue, children = {}})
    return true, nil
end

function GeneralTree:Find(node, value)
    if node == nil then return nil end
    if node.value == value then return node end
    for _, child in ipairs(node.children) do
        local found = self:Find(child, value)
        if found ~= nil then return found end
    end
    return nil
end

function GeneralTree:TraverseBFS(visit)
    if self.root == nil then return end
    local queue = {self.root}
    while #queue > 0 do
        local curr = table.remove(queue, 1)
        visit(curr.value)
        for _, child in ipairs(curr.children) do
            table.insert(queue, child)
        end
    end
end

return tree