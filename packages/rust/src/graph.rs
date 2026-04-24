use std::collections::{HashMap, HashSet, VecDeque};

pub struct Graph {
    pub adj_list: HashMap<usize, Vec<(usize, i32)>>,
}

impl Graph {
    pub fn new() -> Self {
        Graph { adj_list: HashMap::new() }
    }

    pub fn add_edge(&mut self, u: usize, v: usize, weight: i32) {
        self.adj_list.entry(u).or_insert_with(Vec::new).push((v, weight));
        self.adj_list.entry(v).or_insert_with(Vec::new).push((u, weight));
    }

    pub fn bfs(&self, start: usize) -> Vec<usize> {
        let mut visited = HashSet::new();
        let mut queue = VecDeque::new();
        let mut result = Vec::new();

        queue.push_back(start);
        visited.insert(start);

        while let Some(node) = queue.pop_front() {
            result.push(node);
            if let Some(neighbors) = self.adj_list.get(&node) {
                for &(neighbor, _) in neighbors {
                    if !visited.contains(&neighbor) {
                        visited.insert(neighbor);
                        queue.push_back(neighbor);
                    }
                }
            }
        }
        result
    }

    pub fn dfs(&self, start: usize) -> Vec<usize> {
        let mut visited = HashSet::new();
        let mut result = Vec::new();
        self.dfs_recursive(start, &mut visited, &mut result);
        result
    }

    fn dfs_recursive(&self, node: usize, visited: &mut HashSet<usize>, result: &mut Vec<usize>) {
        visited.insert(node);
        result.push(node);
        if let Some(neighbors) = self.adj_list.get(&node) {
            for &(neighbor, _) in neighbors {
                if !visited.contains(&neighbor) {
                    self.dfs_recursive(neighbor, visited, result);
                }
            }
        }
    }

    pub fn kruskal_mst(&self) -> Vec<(usize, usize, i32)> {
        let mut edges = Vec::new();
        let mut nodes = HashSet::new();
        for (&u, neighbors) in &self.adj_list {
            nodes.insert(u);
            for &(v, w) in neighbors {
                if u < v {
                    edges.push((w, u, v));
                }
            }
        }
        edges.sort_by_key(|&(w, _, _)| w);

        let mut parent: HashMap<usize, usize> = nodes.into_iter().map(|n| (n, n)).collect();
        let mut rank: HashMap<usize, usize> = parent.keys().map(|&n| (n, 0)).collect();

        fn find(parent: &mut HashMap<usize, usize>, i: usize) -> usize {
            if parent[&i] == i {
                return i;
            }
            let root = find(parent, parent[&i]);
            parent.insert(i, root);
            root
        }

        fn union(parent: &mut HashMap<usize, usize>, rank: &mut HashMap<usize, usize>, i: usize, j: usize) {
            let root_i = find(parent, i);
            let root_j = find(parent, j);
            if root_i != root_j {
                if rank[&root_i] < rank[&root_j] {
                    parent.insert(root_i, root_j);
                } else if rank[&root_i] > rank[&root_j] {
                    parent.insert(root_j, root_i);
                } else {
                    parent.insert(root_j, root_i);
                    *rank.get_mut(&root_i).unwrap() += 1;
                }
            }
        }

        let mut mst = Vec::new();
        for (w, u, v) in edges {
            if find(&mut parent, u) != find(&mut parent, v) {
                mst.push((u, v, w));
                union(&mut parent, &mut rank, u, v);
            }
        }
        mst
    }
}
