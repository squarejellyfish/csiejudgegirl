#include "construct.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// typedef struct Node{
//     int value;
//     struct Node *left, *right;
// } Node;
Node* link(int T[], int start, int end) {
    if (end == start) return NULL;

    Node* ret = (Node*)malloc(sizeof(Node));
    ret->value = T[end - 1];
    ret->left = link(T, start, end - 1);
    ret->right = NULL;
    return ret;
}

Node* construct(int T[], int start, int end) {
    if (end - start < 3) {
        return link(T, start, end);
    }
    int64_t weight = 0, sum = 0;
    for (int i = start; i < end; i++) {
        weight += T[i] * i;
        sum += T[i];
    }

    if (weight % sum == 0) {
        int idx = weight / sum;
        Node* root = (Node*)malloc(sizeof(Node));
        root->value = T[idx];
        root->left = construct(T, start, idx);
        root->right = construct(T, idx + 1, end);
        return root;
    } else {
        return link(T, start, end);
    }
}
 
Node *ConstructTree(int T[], int N) {
    return construct(T, 0, N);
}
