package graph

// DFS performs a Depth-First Search traversal starting from a specific node.
// It explores as far as possible along each branch before backtracking.
// The provided 'visit' callback is executed exactly once for each reachable node.
// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V) for the call stack and visited map.
func (g *Graph[T]) DFS(start T, visit func(T)) {
	visited := make(map[T]bool) // Tracks vertices to prevent infinite loops.
	g.dfsRecursive(start, visited, visit)
}

// dfsRecursive is the internal recursive helper function for DFS.
func (g *Graph[T]) dfsRecursive(curr T, visited map[T]bool, visit func(T)) {
	visited[curr] = true
	visit(curr) // Execute the callback

	// Deeply explore all unvisited neighbors.
	for _, neighbor := range g.Vertices[curr] {
		if !visited[neighbor] {
			g.dfsRecursive(neighbor, visited, visit)
		}
	}
}
