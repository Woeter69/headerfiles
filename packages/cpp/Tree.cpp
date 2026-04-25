#include "Tree.hpp"
#include <iostream>
#include <algorithm>

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

TrieNode::TrieNode() : isEndOfWord(false) {
    for (int i = 0; i < 26; i++) children[i] = nullptr;
}

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(const std::string& word) {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'a';
        if (!curr->children[index]) {
            curr->children[index] = new TrieNode();
        }
        curr = curr->children[index];
    }
    curr->isEndOfWord = true;
}

bool Trie::search(const std::string& word) const {
    TrieNode* curr = root;
    for (char c : word) {
        int index = c - 'a';
        if (!curr->children[index]) return false;
        curr = curr->children[index];
    }
    return curr != nullptr && curr->isEndOfWord;
}

bool Trie::startsWith(const std::string& prefix) const {
    TrieNode* curr = root;
    for (char c : prefix) {
        int index = c - 'a';
        if (!curr->children[index]) return false;
        curr = curr->children[index];
    }
    return curr != nullptr;
}

AVLNode::AVLNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(AVLNode* N) const {
    if (N == nullptr) return 0;
    return N->height;
}

int AVLTree::getBalance(AVLNode* N) const {
    if (N == nullptr) return 0;
    return height(N->left) - height(N->right);
}

AVLNode* AVLTree::rightRotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    return x;
}

AVLNode* AVLTree::leftRotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    return y;
}

AVLNode* AVLTree::insertNode(AVLNode* node, int val) {
    if (node == nullptr) return new AVLNode(val);
    if (val < node->val) node->left = insertNode(node->left, val);
    else if (val > node->val) node->right = insertNode(node->right, val);
    else return node;

    node->height = 1 + std::max(height(node->left), height(node->right));
    int balance = getBalance(node);

    if (balance > 1 && val < node->left->val) return rightRotate(node);
    if (balance < -1 && val > node->right->val) return leftRotate(node);
    if (balance > 1 && val > node->left->val) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && val < node->right->val) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void AVLTree::insert(int val) {
    root = insertNode(root, val);
}

void AVLTree::inorder(AVLNode* node) const {
    if (node != nullptr) {
        inorder(node->left);
        std::cout << node->val << " ";
        inorder(node->right);
    }
}

void AVLTree::print() const {
    inorder(root);
    std::cout << "\n";
}
