package graph

// Graph represents a generic Adjacency List graph structure.
// The generic type T MUST be comparable (e.g., string, int) so it can act as a map key.
// This implementation supports both directed and undirected graphs.
type Graph[T comparable] struct {
	Vertices map[T][]T // A map associating a vertex with a slice of its neighboring vertices.
}

// New creates and returns a new, empty generic Graph.
func New[T comparable]() *Graph[T] {
	return &Graph[T]{
		Vertices: make(map[T][]T),
	}
}

// AddVertex registers a new vertex in the graph.
// If the vertex already exists, it does nothing.
// Time Complexity: O(1)
func (g *Graph[T]) AddVertex(v T) {
	if _, exists := g.Vertices[v]; !exists {
		g.Vertices[v] = []T{}
	}
}

// AddEdge creates a directed edge starting from vertex 'u' and ending at vertex 'v'.
// It automatically adds the vertices to the graph if they do not already exist.
// Time Complexity: O(1) amortized
func (g *Graph[T]) AddEdge(u, v T) {
	g.AddVertex(u)
	g.AddVertex(v)
	g.Vertices[u] = append(g.Vertices[u], v)
}

// AddUndirectedEdge creates an undirected (bi-directional) edge between vertex 'u' and vertex 'v'.
// It is equivalent to calling AddEdge(u, v) and AddEdge(v, u).
// Time Complexity: O(1) amortized
func (g *Graph[T]) AddUndirectedEdge(u, v T) {
	g.AddEdge(u, v)
	g.AddEdge(v, u)
}

// GetNeighbors retrieves the slice of neighbors directly connected to vertex 'v'.
// Time Complexity: O(1)
func (g *Graph[T]) GetNeighbors(v T) []T {
	return g.Vertices[v]
}
