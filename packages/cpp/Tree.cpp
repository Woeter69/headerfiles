#include "Tree.hpp"
#include <iostream>

BSTNode::BSTNode(int x) : val(x), left(nullptr), right(nullptr) {}

BST::BST() : root(nullptr) {}

void BST::insert(int val) {
    if (!root) {
        root = new BSTNode(val);
        return;
    }
    BSTNode* curr = root;
    while (true) {
        if (val < curr->val) {
            if (!curr->left) {
                curr->left = new BSTNode(val);
                break;
            }
            curr = curr->left;
        } else {
            if (!curr->right) {
                curr->right = new BSTNode(val);
                break;
            }
            curr = curr->right;
        }
    }
}

void BST::inorder(BSTNode* node) const {
    if (!node) return;
    inorder(node->left);
    std::cout << node->val << " ";
    inorder(node->right);
}

void BST::print() const {
    inorder(root);
    std::cout << "\n";
}

TreeNode::TreeNode(int x) : val(x) {}

Tree::Tree() : root(nullptr) {}

void Tree::setRoot(int val) {
    root = new TreeNode(val);
}

TreeNode* Tree::getRoot() const {
    return root;
}
