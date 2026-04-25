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

-- --- Trie ---
local TrieNode = {}
TrieNode.__index = TrieNode

function TrieNode.new()
    return setmetatable({children = {}, isEndOfWord = false}, TrieNode)
end

local Trie = {}
Trie.__index = Trie

function tree.NewTrie()
    return setmetatable({root = TrieNode.new()}, Trie)
end

function Trie:Insert(word)
    local curr = self.root
    for i = 1, #word do
        local char = word:sub(i, i)
        if not curr.children[char] then
            curr.children[char] = TrieNode.new()
        end
        curr = curr.children[char]
    end
    curr.isEndOfWord = true
end

function Trie:Search(word)
    local curr = self.root
    for i = 1, #word do
        local char = word:sub(i, i)
        if not curr.children[char] then
            return false
        end
        curr = curr.children[char]
    end
    return curr.isEndOfWord
end

function Trie:StartsWith(prefix)
    local curr = self.root
    for i = 1, #prefix do
        local char = prefix:sub(i, i)
        if not curr.children[char] then
            return false
        end
        curr = curr.children[char]
    end
    return true
end

-- --- AVL Tree ---
local AVLTree = {}
AVLTree.__index = AVLTree

function tree.NewAVLTree(less)
    return setmetatable({root = nil, less = less}, AVLTree)
end

function AVLTree:_height(node)
    if node == nil then return 0 end
    return node.height
end

function AVLTree:_updateHeight(node)
    local leftH = self:_height(node.left)
    local rightH = self:_height(node.right)
    node.height = (leftH > rightH and leftH or rightH) + 1
end

function AVLTree:_getBalance(node)
    if node == nil then return 0 end
    return self:_height(node.left) - self:_height(node.right)
end

function AVLTree:_rightRotate(y)
    local x = y.left
    local T2 = x.right
    x.right = y
    y.left = T2
    self:_updateHeight(y)
    self:_updateHeight(x)
    return x
end

function AVLTree:_leftRotate(x)
    local y = x.right
    local T2 = y.left
    y.left = x
    x.right = T2
    self:_updateHeight(x)
    self:_updateHeight(y)
    return y
end

function AVLTree:Insert(value)
    self.root = self:_insert(self.root, value)
end

function AVLTree:_insert(node, value)
    if node == nil then
        return {value = value, left = nil, right = nil, height = 1}
    end

    if self.less(value, node.value) then
        node.left = self:_insert(node.left, value)
    elseif self.less(node.value, value) then
        node.right = self:_insert(node.right, value)
    else
        return node
    end

    self:_updateHeight(node)
    local balance = self:_getBalance(node)

    if balance > 1 and self.less(value, node.left.value) then
        return self:_rightRotate(node)
    end
    if balance < -1 and self.less(node.right.value, value) then
        return self:_leftRotate(node)
    end
    if balance > 1 and self.less(node.left.value, value) then
        node.left = self:_leftRotate(node.left)
        return self:_rightRotate(node)
    end
    if balance < -1 and self.less(value, node.right.value) then
        node.right = self:_rightRotate(node.right)
        return self:_leftRotate(node)
    end

    return node
end

function AVLTree:Search(value)
    return self:_search(self.root, value)
end

function AVLTree:_search(node, value)
    if node == nil then return false end
    if not self.less(value, node.value) and not self.less(node.value, value) then
        return true
    end
    if self.less(value, node.value) then
        return self:_search(node.left, value)
    end
    return self:_search(node.right, value)
end

return tree