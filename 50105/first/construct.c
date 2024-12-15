#include "construct.h"
#include <stdlib.h>
#include <stdint.h>

/*
typedef struct Node{
    int value;
    struct Node *left, *right;
} Node;
*/
Node *link(int l, int r, int T[]) {
    if (r - 1 < l) return NULL;
    Node *root = (Node *)malloc(sizeof(Node));
    root->value = T[r - 1];
    root->right = NULL;
    root->left = link(l, r - 1, T);
    return root;
}

Node *construct(int l, int r, int T[]) {
    if (r - l < 3) { // length < 3
        return link(l, r, T);
    }
    int64_t weight = 0, sum = 0;
    for (int i = l; i < r; i++) {
        weight += T[i] * i;
        sum += T[i];
    }
    if (weight % sum == 0) {
        Node *root = (Node *)malloc(sizeof(Node));
        int64_t mid = weight / sum;
        root->value = T[mid];
        root->left = construct(l, mid, T);
        root->right = construct(mid + 1, r, T);
        return root;
    } else { // no balancing point
        return link(l, r, T);
    }
}

Node *ConstructTree(int T[], int N) {
    return construct(0, N, T);
}
