#include "buildTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct Node
// {
//     char* val;
//     struct Node *left, *right;
// } Node;

Node* expression(char* expr) {
    Node* ret = (Node*)malloc(sizeof(Node));
    printf("current expr = %s\n", expr);
    if (strcmp(expr, "!") == 0) {
        ret->val = expr;
        expr = strtok(NULL, " "); // skip !
        ret->left = expression(expr);
        ret->right = NULL;
    } else if (strcmp(expr, "(") == 0) {
        expr = strtok(NULL, " "); // skip left paren
        ret->left = expression(expr);
        ret->val = expr;
        expr = strtok(NULL, " "); // skip op
        ret->right = expression(expr);
        expr = strtok(NULL, " "); // skip right paren
    } else {
        ret->val = expr;
        expr = strtok(NULL, " "); // skip self
        ret->left = NULL;
        ret->right = NULL;
    }
    return ret;
}

Node* buildTree(char* expr) {
    expr = strtok(expr, " ");
    return expression(expr);
}
