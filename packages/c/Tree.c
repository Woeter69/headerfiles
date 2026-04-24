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