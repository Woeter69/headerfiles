package graph

// BFS performs a Breadth-First Search traversal starting from a specific node.
// It visits all nodes at the present depth before moving on to nodes at the next depth level.
// The provided 'visit' callback is executed exactly once for each reachable node.
// Time Complexity: O(V + E) where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V) for the queue and visited map.
func (g *Graph[T]) BFS(start T, visit func(T)) {
	visited := make(map[T]bool) // Tracks vertices to avoid infinite loops in cycles.
	queue := []T{start}         // The queue guiding the BFS logic.
	visited[start] = true

	for len(queue) > 0 {
		curr := queue[0]
		queue = queue[1:]
		
		// Execute the callback for the current node.
		visit(curr)

		// Queue all unvisited neighbors.
		for _, neighbor := range g.Vertices[curr] {
			if !visited[neighbor] {
				visited[neighbor] = true
				queue = append(queue, neighbor)
			}
		}
	}
}
