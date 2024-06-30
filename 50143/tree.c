#include "tree.h"
#include <stdlib.h>

/*
typedef struct Node{
    int val;
    struct Node *left, *right;
} Node;
*/
 
Node *treeAND(Node *root1, Node *root2) {
    if (!root1 || !root2) return NULL;

    Node *ret = (Node*)malloc(sizeof(Node));
    ret->val = root1->val * root2->val;
    ret->left = treeAND(root1->left, root2->left);
    ret->right = treeAND(root1->right, root2->right);

    return ret;
}
Node *treeOR(Node *root1, Node *root2) {
    if (!root1 && !root2) return NULL;
    if (root1 && !root2) return root1;
    if (!root1 && root2) return root2;

    Node *ret = (Node*)malloc(sizeof(Node));
    ret->val = root1->val + root2->val;
    ret->left = treeOR(root1->left, root2->left);
    ret->right = treeOR(root1->right, root2->right);

    return ret;
}
