#include "operations.h"
#include <stdlib.h>
#include <stdio.h>

/*
typedef struct Node{
    int n;
    struct Node *left, *right;
} Node;
*/

Node *flip(Node *new, Node *old) {
    if (old == NULL) return NULL;

    Node *ret = (Node*)malloc(sizeof(Node));
    ret->n = old->n;
    ret->left = flip(ret->left, old->right);
    ret->right = flip(ret->right, old->left);
    return ret;
}

Node *FlipTree(Node *root) {
    Node *new;
    new = flip(new, root);
    return new;
}
int isIdentical(Node *tree1, Node *tree2) {
    if (tree1 == NULL) {
        if (tree2 == NULL) return 1;
        else return 0;
    }
    if (tree2 == NULL) {
        if (tree1 == NULL) return 1;
        else return 0;
    }

    if (tree1->n == tree2->n) {
        if (isIdentical(tree1->left, tree2->left) && isIdentical(tree1->right, tree2->right))
            return 1;
    }
    return 0;
}
int leaves, sum;
void find(Node *root, int depth) {
    if (root->left == NULL && root->right == NULL) {
        leaves++;
        sum += depth;
        return;
    }

    if (root->left) {
        find(root->left, depth + 1);
    } 
    if (root->right) {
        find(root->right, depth + 1);
    }
}

void depthAvg(Node *root) {
    leaves = sum = 0;
    find(root, 0);
    printf("%d/%d\n", sum, leaves);
}
