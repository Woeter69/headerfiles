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