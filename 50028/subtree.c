#include "subtree.h"
#include <stdlib.h>

int i = 0;

int solve(Node *root, int arr[], int k) {
    if (!root) {
        return 0;
    }
    int left = solve(root->left, arr, k);
    int right = solve(root->right, arr, k);

    if (left && right && root->label != k) {
        arr[i] = root->label;
        i++;
    }
    return left || right || root->label == k;
}

int getNode(Node *root, int label[], int k) {
    i = 0;
    solve(root, label, k);

    return i;
}
