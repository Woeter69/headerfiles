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

#endif