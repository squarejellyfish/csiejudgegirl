#include "tree.h"
#include <stdio.h>

Node *path[1024];
int depth = 0;

void traversal(Node *root, int N, int command[]) {
    Node *curr = root;
    for (int i = 0; i < N; i++) {
        int t = command[i];
        if (t == 0) {
            printf("%d\n", curr->label);
            return;
        } else if (t == 1) {
            printf("%d\n", curr->label);
        } else if (t == 2) {
            if (depth) {
                curr = path[depth - 1];
                depth--;
            } else {
                printf("%d\n", curr->label);
                return;
            }
        } else if (t == 3) {
            if (curr->left) {
                path[depth++] = curr;
                curr = curr->left;
            } else {
                printf("%d\n", curr->label);
                return;
            }
        } else if (t == 4) {
            if (curr->right) {
                path[depth++] = curr;
                curr = curr->right;
            } else {
                printf("%d\n", curr->label);
                return;
            }
        } else if (t == 5) {
            if (depth) {
                Node *parent = path[depth - 1];
                Node *next = (parent->left != curr) ? parent->left : parent->right;
                if (next) {
                    curr = next;
                    path[depth] = curr;
                } else {
                    printf("%d\n", curr->label);
                    return;
                }
            } else {
                printf("%d\n", curr->label);
                return;
            }
        }
    }
}
