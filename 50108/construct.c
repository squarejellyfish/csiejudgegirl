#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "construct.h"

/*
typedef struct node{
    int value;
    struct node *left, *right;
} Node;
*/

Node *link(int l, int r, int seq[]) {
    if (r - 1 < l) return NULL;
    Node *ret = (Node*)malloc(sizeof(Node));
    ret->value = seq[r - 1];
    // printf("linked %d\n", ret->value);
    ret->right = NULL;
    ret->left = link(l, r - 1, seq);
    return ret;
}

int b[16284];
int cmp(const void *p1, const void *p2) {
    return *((int*)p2) - *((int*)p1);
}

Node *construct(int l, int r, int seq[]) {
    if (r - l < MAXLENGTH) {
        // printf("linking %d to %d\n", l, r);
        return link(l, r, seq);
    }
    memcpy(b, seq + l, sizeof(int) * (r - l));
    qsort(b, r - l, sizeof(int), cmp);
    int next = b[MAXLENGTH - 1], idx;
    for (idx = l; idx < r; idx++) if (seq[idx] == next) break;
    // printf("next is %d, index = %d\n", next, idx);

    Node *ret = (Node*)malloc(sizeof(Node));
    ret->value = next;
    ret->left = construct(l, idx, seq);
    ret->right = construct(idx + 1, r, seq);
    return ret;
}

Node* ConstructTree(int sequence[], int N) {
    return construct(0, N, sequence);
}
