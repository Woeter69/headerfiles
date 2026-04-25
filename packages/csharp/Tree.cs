namespace csharp_packages;
using System.Collections.Generic;
using System;

public class BSTNode<T> {
    public T Data;
    public BSTNode<T>? Left, Right;
    public BSTNode(T data) { Data = data; }
}

public class BST<T> where T : IComparable<T> {
    public BSTNode<T>? Root;
    public void Insert(T data) {
        Root = InsertRec(Root, data);
    }
    private BSTNode<T> InsertRec(BSTNode<T>? root, T data) {
        if (root == null) return new BSTNode<T>(data);
        if (data.CompareTo(root.Data) < 0)
            root.Left = InsertRec(root.Left, data);
        else if (data.CompareTo(root.Data) > 0)
            root.Right = InsertRec(root.Right, data);
        return root;
    }
}

public class NaryTreeNode<T> {
    public T Data;
    public List<NaryTreeNode<T>> Children = new();
    public NaryTreeNode(T data) { Data = data; }
}

public class NaryTree<T> {
    public NaryTreeNode<T>? Root;
}

public class TrieNode {
    public System.Collections.Generic.Dictionary<char, TrieNode> Children = new();
    public bool IsEndOfWord;
}

public class Trie {
    private readonly TrieNode _root = new();
    
    public void Insert(string word) {
        var curr = _root;
        foreach (char c in word) {
            if (!curr.Children.ContainsKey(c)) {
                curr.Children[c] = new TrieNode();
            }
            curr = curr.Children[c];
        }
        curr.IsEndOfWord = true;
    }
    
    public bool Search(string word) {
        var node = SearchPrefix(word);
        return node != null && node.IsEndOfWord;
    }
    
    public bool StartsWith(string prefix) {
        return SearchPrefix(prefix) != null;
    }
    
    private TrieNode? SearchPrefix(string prefix) {
        var curr = _root;
        foreach (char c in prefix) {
            if (!curr.Children.ContainsKey(c)) return null;
            curr = curr.Children[c];
        }
        return curr;
    }
}

public class AVLTreeNode<T> {
    public T Data;
    public AVLTreeNode<T>? Left, Right;
    public int Height = 1;
    public AVLTreeNode(T data) { Data = data; }
}

public class AVLTree<T> where T : System.IComparable<T> {
    public AVLTreeNode<T>? Root;
    
    public void Insert(T data) {
        Root = InsertRec(Root, data);
    }
    
    private AVLTreeNode<T> InsertRec(AVLTreeNode<T>? node, T data) {
        if (node == null) return new AVLTreeNode<T>(data);
        
        int cmp = data.CompareTo(node.Data);
        if (cmp < 0) node.Left = InsertRec(node.Left, data);
        else if (cmp > 0) node.Right = InsertRec(node.Right, data);
        else return node; 
        
        node.Height = 1 + System.Math.Max(GetHeight(node.Left), GetHeight(node.Right));
        int balance = GetBalance(node);
        
        if (balance > 1 && data.CompareTo(node.Left!.Data) < 0) return RightRotate(node);
        if (balance < -1 && data.CompareTo(node.Right!.Data) > 0) return LeftRotate(node);
        if (balance > 1 && data.CompareTo(node.Left!.Data) > 0) {
            node.Left = LeftRotate(node.Left);
            return RightRotate(node);
        }
        if (balance < -1 && data.CompareTo(node.Right!.Data) < 0) {
            node.Right = RightRotate(node.Right);
            return LeftRotate(node);
        }
        return node;
    }
    
    private int GetHeight(AVLTreeNode<T>? node) => node?.Height ?? 0;
    
    private int GetBalance(AVLTreeNode<T>? node) => node == null ? 0 : GetHeight(node.Left) - GetHeight(node.Right);
    
    private AVLTreeNode<T> RightRotate(AVLTreeNode<T> y) {
        var x = y.Left!;
        var T2 = x.Right;
        x.Right = y;
        y.Left = T2;
        y.Height = 1 + System.Math.Max(GetHeight(y.Left), GetHeight(y.Right));
        x.Height = 1 + System.Math.Max(GetHeight(x.Left), GetHeight(x.Right));
        return x;
    }
    
    private AVLTreeNode<T> LeftRotate(AVLTreeNode<T> x) {
        var y = x.Right!;
        var T2 = y.Left;
        y.Left = x;
        x.Right = T2;
        x.Height = 1 + System.Math.Max(GetHeight(x.Left), GetHeight(x.Right));
        y.Height = 1 + System.Math.Max(GetHeight(y.Left), GetHeight(y.Right));
        return y;
    }
}