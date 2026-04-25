#include "Tree.h"
#include <stdlib.h>
#include <stdio.h>

BSTNode* bst_insert(BSTNode* root, int val) {
    if (!root) {
        BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
        node->data = val;
        node->left = node->right = NULL;
        return node;
    }
    if (val < root->data) root->left = bst_insert(root->left, val);
    else if (val > root->data) root->right = bst_insert(root->right, val);
    return root;
}
void bst_inorder(BSTNode* root) {
    if (root) {
        bst_inorder(root->left);
        printf("%d ", root->data);
        bst_inorder(root->right);
    }
}
void bst_free(BSTNode* root) {
    if (root) {
        bst_free(root->left);
        bst_free(root->right);
        free(root);
    }
}

NaryNode* nary_create(int val, int child_count) {
    NaryNode* node = (NaryNode*)malloc(sizeof(NaryNode));
    node->data = val;
    node->child_count = child_count;
    node->children = (NaryNode**)malloc(sizeof(NaryNode*) * child_count);
    for(int i=0; i<child_count; i++) node->children[i] = NULL;
    return node;
}
void nary_free(NaryNode* root) {
    if (root) {
        for (int i = 0; i < root->child_count; i++) {
            nary_free(root->children[i]);
        }
        free(root->children);
        free(root);
    }
}

TrieNode* trie_create() {
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));
    node->is_end_of_word = 0;
    for (int i = 0; i < 26; i++) {
        node->children[i] = NULL;
    }
    return node;
}

void trie_insert(TrieNode* root, const char* word) {
    TrieNode* curr = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!curr->children[index]) {
            curr->children[index] = trie_create();
        }
        curr = curr->children[index];
    }
    curr->is_end_of_word = 1;
}

int trie_search(TrieNode* root, const char* word) {
    TrieNode* curr = root;
    for (int i = 0; word[i] != '\0'; i++) {
        int index = word[i] - 'a';
        if (!curr->children[index]) {
            return 0;
        }
        curr = curr->children[index];
    }
    return curr != NULL && curr->is_end_of_word;
}

void trie_free(TrieNode* root) {
    if (root) {
        for (int i = 0; i < 26; i++) {
            trie_free(root->children[i]);
        }
        free(root);
    }
}

int avl_height(AVLNode* n) {
    if (!n) return 0;
    return n->height;
}

int avl_get_balance(AVLNode* n) {
    if (!n) return 0;
    return avl_height(n->left) - avl_height(n->right);
}

AVLNode* avl_create_node(int data) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->data = data;
    node->left = node->right = NULL;
    node->height = 1;
    return node;
}

AVLNode* avl_right_rotate(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = 1 + (avl_height(y->left) > avl_height(y->right) ? avl_height(y->left) : avl_height(y->right));
    x->height = 1 + (avl_height(x->left) > avl_height(x->right) ? avl_height(x->left) : avl_height(x->right));
    return x;
}

AVLNode* avl_left_rotate(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = 1 + (avl_height(x->left) > avl_height(x->right) ? avl_height(x->left) : avl_height(x->right));
    y->height = 1 + (avl_height(y->left) > avl_height(y->right) ? avl_height(y->left) : avl_height(y->right));
    return y;
}

AVLNode* avl_insert(AVLNode* node, int data) {
    if (!node) return avl_create_node(data);
    if (data < node->data)
        node->left = avl_insert(node->left, data);
    else if (data > node->data)
        node->right = avl_insert(node->right, data);
    else
        return node;

    node->height = 1 + (avl_height(node->left) > avl_height(node->right) ? avl_height(node->left) : avl_height(node->right));

    int balance = avl_get_balance(node);

    if (balance > 1 && data < node->left->data)
        return avl_right_rotate(node);

    if (balance < -1 && data > node->right->data)
        return avl_left_rotate(node);

    if (balance > 1 && data > node->left->data) {
        node->left = avl_left_rotate(node->left);
        return avl_right_rotate(node);
    }

    if (balance < -1 && data < node->right->data) {
        node->right = avl_right_rotate(node->right);
        return avl_left_rotate(node);
    }

    return node;
}

void avl_inorder(AVLNode* root) {
    if (root) {
        avl_inorder(root->left);
        printf("%d ", root->data);
        avl_inorder(root->right);
    }
}

void avl_free(AVLNode* root) {
    if (root) {
        avl_free(root->left);
        avl_free(root->right);
        free(root);
    }
}