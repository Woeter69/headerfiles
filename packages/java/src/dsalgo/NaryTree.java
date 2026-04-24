package dsalgo;

import java.util.ArrayList;
import java.util.List;

public class NaryTree<T> {
    private class Node {
        T data;
        List<Node> children;
        Node(T data) { 
            this.data = data;
            this.children = new ArrayList<>();
        }
    }
    private Node root;

    public NaryTree(T rootData) {
        root = new Node(rootData);
    }

    public Node getRoot() {
        return root;
    }

    public void addChild(Node parent, T data) {
        if (parent != null) {
            parent.children.add(new Node(data));
        }
    }

    public void printTree(Node node, String prefix) {
        if (node == null) return;
        System.out.println(prefix + node.data);
        for (Node child : node.children) {
            printTree(child, prefix + "  ");
        }
    }
}
