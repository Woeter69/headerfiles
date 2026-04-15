#pragma once
#include <vector>

struct BSTNode {
    int val;
    BSTNode *left, *right;
    BSTNode(int x);
};

class BST {
    BSTNode* root;
    void inorder(BSTNode* node) const;
public:
    BST();
    void insert(int val);
    void print() const;
};

struct TreeNode {
    int val;
    std::vector<TreeNode*> children;
    TreeNode(int x);
};

class Tree {
    TreeNode* root;
public:
    Tree();
    void setRoot(int val);
    TreeNode* getRoot() const;
};
