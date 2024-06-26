#include "construct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct Node{
    char name[16];
    int height;
    int weight;
    struct Node *left, *right;
} Node;
*/

Node *insert(Node *root, char name[16], int height, int weight) {
    if (root == NULL) {
        Node *ret = (Node*)malloc(sizeof(Node));
        strcpy(ret->name, name);
        ret->height = height;
        ret->weight = weight;
        ret->left = NULL;
        ret->right = NULL;
//        printf("inserted %s\n", ret->name);
        return ret;
    }
#ifdef HEIGHT
    if (height < root->height) {
        root->left = insert(root->left, name, height, weight);
    } else {
        root->right = insert(root->right, name, height, weight);
    }
#endif
#ifdef WEIGHT
    if (weight < root->weight) {
        root->left = insert(root->left, name, height, weight);
    } else {
        root->right = insert(root->right, name, height, weight);
    }
#endif
    return root;
}

Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]) {
    Node *root = NULL;
    for (int i = 0; i < N; i++) {
        root = insert(root, name[i], height[i], weight[i]);
    }
    return root;
}
