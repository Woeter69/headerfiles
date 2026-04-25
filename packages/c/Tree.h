#ifndef TREE_H
#define TREE_H

typedef struct BSTNode {
    int data;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* bst_insert(BSTNode* root, int val);
void bst_inorder(BSTNode* root);
void bst_free(BSTNode* root);

typedef struct NaryNode {
    int data;
    int child_count;
    struct NaryNode** children;
} NaryNode;

NaryNode* nary_create(int val, int child_count);
void nary_free(NaryNode* root);

typedef struct TrieNode {
    struct TrieNode* children[26];
    int is_end_of_word;
} TrieNode;

TrieNode* trie_create();
void trie_insert(TrieNode* root, const char* word);
int trie_search(TrieNode* root, const char* word);
void trie_free(TrieNode* root);

typedef struct AVLNode {
    int data;
    struct AVLNode* left;
    struct AVLNode* right;
    int height;
} AVLNode;

int avl_height(AVLNode* n);
int avl_get_balance(AVLNode* n);
AVLNode* avl_insert(AVLNode* node, int data);
void avl_inorder(AVLNode* root);
void avl_free(AVLNode* root);

#endif