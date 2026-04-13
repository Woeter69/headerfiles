local graph = {}

local Graph = {}
Graph.__index = Graph

function graph.New()
    return setmetatable({vertices = {}}, Graph)
end

function Graph:AddVertex(v)
    if self.vertices[v] == nil then
        self.vertices[v] = {}
    end
end

function Graph:AddEdge(u, v)
    self:AddVertex(u)
    self:AddVertex(v)
    table.insert(self.vertices[u], v)
end

function Graph:AddUndirectedEdge(u, v)
    self:AddEdge(u, v)
    self:AddEdge(v, u)
end

function Graph:GetNeighbors(v)
    return self.vertices[v] or {}
end

function Graph:BFS(start, visit)
    local visited = {}
    local queue = {start}
    visited[start] = true

    while #queue > 0 do
        local curr = table.remove(queue, 1)
        visit(curr)
        for _, neighbor in ipairs(self.vertices[curr] or {}) do
            if not visited[neighbor] then
                visited[neighbor] = true
                table.insert(queue, neighbor)
            end
        end
    end
end

function Graph:DFS(start, visit)
    local visited = {}
    self:_dfsRecursive(start, visited, visit)
end

function Graph:_dfsRecursive(curr, visited, visit)
    visited[curr] = true
    visit(curr)
    for _, neighbor in ipairs(self.vertices[curr] or {}) do
        if not visited[neighbor] then
            self:_dfsRecursive(neighbor, visited, visit)
        end
    end
end

function graph.KruskalMST(vertices, edges)
    table.sort(edges, function(a, b) return a.weight < b.weight end)

    local parent = {}
    for _, v in ipairs(vertices) do
        parent[v] = v
    end

    local function find(i)
        if parent[i] == i then return i end
        parent[i] = find(parent[i])
        return parent[i]
    end

    local function union(i, j)
        local rootI = find(i)
        local rootJ = find(j)
        if rootI ~= rootJ then
            parent[rootI] = rootJ
        end
    end

    local mst = {}
    for _, edge in ipairs(edges) do
        if find(edge.u) ~= find(edge.v) then
            table.insert(mst, edge)
            union(edge.u, edge.v)
        end
    end

    return mst
end

return graph