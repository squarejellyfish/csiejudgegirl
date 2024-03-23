#include "tree.h"
#include <stdlib.h>

int i = 0;

Node* construct(int array[], int n) {
    Node* root = (Node*)malloc(sizeof(Node));
    root->label = array[i];
    if (2 * i + 1 < n) {
        root->left = (Node*)malloc(sizeof(Node));
        int temp = i;
        i = 2 * i + 1;
        root->left = construct(array, n);
        i = temp;
    }
    if (2 * i + 2 < n) {
        root->right = (Node*)malloc(sizeof(Node));
        int tmep = i;
        i = 2 * i + 2;
        root->right = construct(array, n);
        i = tmep;
    }
    return root;
}
