#pragma once
#include <vector>
#include <string>

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

struct TrieNode {
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode();
};

class Trie {
    TrieNode* root;
public:
    Trie();
    void insert(const std::string& word);
    bool search(const std::string& word) const;
    bool startsWith(const std::string& prefix) const;
};

struct AVLNode {
    int val;
    AVLNode* left;
    AVLNode* right;
    int height;
    AVLNode(int x);
};

class AVLTree {
    AVLNode* root;
    int height(AVLNode* N) const;
    int getBalance(AVLNode* N) const;
    AVLNode* rightRotate(AVLNode* y);
    AVLNode* leftRotate(AVLNode* x);
    AVLNode* insertNode(AVLNode* node, int val);
    void inorder(AVLNode* node) const;
public:
    AVLTree();
    void insert(int val);
    void print() const;
};
