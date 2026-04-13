package graph

import "sort"

// Edge represents a connection between two vertices (U and V) with an associated Weight.
// It is utilized heavily in Spanning Tree algorithms like Kruskal's or Prim's.
type Edge[T comparable] struct {
	U      T   // The starting vertex
	V      T   // The ending vertex
	Weight int // The numerical cost/weight of the edge
}

// KruskalMST computes the Minimum Spanning Tree of a graph using Kruskal's Algorithm.
// It takes a complete list of vertices and edges, sorts the edges by weight,
// and employs a Disjoint Set (Union-Find) data structure to select edges
// without forming cycles until all vertices are connected.
// Returns a slice of edges that make up the MST.
// Time Complexity: O(E log E) for sorting edges, plus O(E * α(V)) for Union-Find operations.
func KruskalMST[T comparable](vertices []T, edges []Edge[T]) []Edge[T] {
	// Step 1: Sort all edges in non-decreasing order of their weight.
	sort.Slice(edges, func(i, j int) bool {
		return edges[i].Weight < edges[j].Weight
	})

	// Setup Disjoint Set (Union-Find) parent map
	parent := make(map[T]T)
	for _, v := range vertices {
		parent[v] = v
	}

	// Find function with path compression to optimize future lookups.
	var find func(T) T
	find = func(i T) T {
		if parent[i] == i {
			return i
		}
		parent[i] = find(parent[i]) // Path compression
		return parent[i]
	}

	// Union function to merge two sets.
	union := func(i, j T) {
		rootI := find(i)
		rootJ := find(j)
		if rootI != rootJ {
			parent[rootI] = rootJ
		}
	}

	// Step 2: Iterate through sorted edges and pick those that do not form a cycle.
	mst := []Edge[T]{}
	for _, edge := range edges {
		// If including this edge doesn't cause cycle, include it.
		if find(edge.U) != find(edge.V) {
			mst = append(mst, edge)
			union(edge.U, edge.V)
		}
	}

	return mst
}
