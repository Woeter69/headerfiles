package dsalgo;

public class BST<T extends Comparable<T>> {
    private class Node {
        T data;
        Node left, right;
        Node(T data) { this.data = data; }
    }
    private Node root;

    public void insert(T data) {
        root = insertRec(root, data);
    }

    private Node insertRec(Node root, T data) {
        if (root == null) {
            root = new Node(data);
            return root;
        }
        if (data.compareTo(root.data) < 0)
            root.left = insertRec(root.left, data);
        else if (data.compareTo(root.data) > 0)
            root.right = insertRec(root.right, data);
        return root;
    }

    public boolean search(T data) {
        return searchRec(root, data);
    }

    private boolean searchRec(Node root, T data) {
        if (root == null) return false;
        if (root.data.equals(data)) return true;
        if (data.compareTo(root.data) < 0) return searchRec(root.left, data);
        return searchRec(root.right, data);
    }
    
    public void inorder() {
        inorderRec(root);
        System.out.println();
    }

    private void inorderRec(Node root) {
        if (root != null) {
            inorderRec(root.left);
            System.out.print(root.data + " ");
            inorderRec(root.right);
        }
    }
}
