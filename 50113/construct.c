#include "construct.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct node{
    int small,large;
    struct node *left,*mid,*right;
} Node;
*/

Node *insert(Node *root, int num) {
    if (root == NULL) {
        Node *ret = (Node*)malloc(sizeof(Node));
        ret->large = num;
        ret->small = -1;
        ret->left = NULL;
        ret->mid = NULL;
        ret->right = NULL;
        return ret;
    }
    if (root->small == -1) {
        if (num < root->large) {
            root->small = num;
        } else {
            root->small = root->large;
            root->large = num;
        }
    }
    else if (num < root->small) {
        root->left = insert(root->left, num);
    }
    else if (num > root->small && num < root->large) {
        root->mid = insert(root->mid, num);
    }
    else if (num > root->large) {
        root->right = insert(root->right, num);
    }
    return root;
}

Node *ConstructTree(int sequence[],int N) {
    Node *ret = NULL;
    for (int i = 0; i < N; i++) {
        ret = insert(ret, sequence[i]);
    }
    return ret;
}
