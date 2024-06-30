#include "tree.h"
#include <stdlib.h>
#include <stdio.h>

/*
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;
*/

Node *construct(Node *root, char instruction[MAXN]) {
//    printf("instruction: %c\n", instruction[0]);
    if (root == NULL) {
//        printf("root is NULL, constructing...\n");
        root = (Node*)malloc(sizeof(Node));
        root->data = 1;
        root->left = NULL;
        root->right = NULL;
    } else {
        root->data++;
    }
    if (instruction[0] == 'L') {
        root->left = construct(root->left, instruction + 1);
    } else if (instruction[0] == 'R') {
        root->right = construct(root->right, instruction + 1);
    }
    return root;
}
int query(Node *root, char instruction[MAXN]) {
    if (root == NULL) return 0;

    if (instruction[0] == 'L') {
        return query(root->left, instruction + 1);
    } else if (instruction[0] == 'R') {
        return query(root->right, instruction + 1);
    }
    return root->data;
}
