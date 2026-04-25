package tree

// TrieNode represents a single node in a Trie.
type TrieNode struct {
	Children map[rune]*TrieNode
	IsEnd    bool
}

// Trie represents a Prefix Tree for strings.
type Trie struct {
	Root *TrieNode
}

// NewTrie creates and returns a new empty Trie.
func NewTrie() *Trie {
	return &Trie{Root: &TrieNode{Children: make(map[rune]*TrieNode)}}
}

// Insert adds a word to the Trie.
func (t *Trie) Insert(word string) {
	curr := t.Root
	for _, ch := range word {
		if _, ok := curr.Children[ch]; !ok {
			curr.Children[ch] = &TrieNode{Children: make(map[rune]*TrieNode)}
		}
		curr = curr.Children[ch]
	}
	curr.IsEnd = true
}

// Search returns true if the exact word is in the Trie.
func (t *Trie) Search(word string) bool {
	curr := t.Root
	for _, ch := range word {
		if _, ok := curr.Children[ch]; !ok {
			return false
		}
		curr = curr.Children[ch]
	}
	return curr.IsEnd
}

// StartsWith returns true if there is any word in the Trie that starts with the given prefix.
func (t *Trie) StartsWith(prefix string) bool {
	curr := t.Root
	for _, ch := range prefix {
		if _, ok := curr.Children[ch]; !ok {
			return false
		}
		curr = curr.Children[ch]
	}
	return true
}
