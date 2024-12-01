#include "buildTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct Node
// {
//     char* val;
//     struct Node *left, *right;
// } Node;
typedef struct info {
    Node* root;
    int end;
} Info;

Node* new_node(char* c) {
    Node* ret = (Node*)malloc(sizeof(Node));
    ret->val = c;
    ret->left = NULL;
    ret->right = NULL;
    return ret;
}
Info expression(char* tokens[], int idx) {
    char* tok = tokens[idx];
    if (tok[0] == '!') {
        Node* curr = new_node(tok);
        Info info = expression(tokens, idx + 1);
        curr->left = info.root;
        curr->right = NULL;
        return (Info) {curr, info.end};
    } else if (tok[0] == '(') {
        Info left = expression(tokens, idx + 1);
        Info right = expression(tokens, left.end + 1);

        Node* curr = new_node(tokens[left.end]);
        curr->left = left.root;
        curr->right = right.root;
        return (Info) {curr, right.end + 1};
    } else return (Info) {new_node(tokens[idx]), idx + 1};
}

Node* buildTree(char* expr) {
    char* exp[500001]; int n = 0;
    char* tok = strtok(expr, " ");
    while (tok) {
        exp[n++] = tok;
        tok = strtok(NULL, " ");
    }
    Info info = expression(exp, 0);
    return info.root;
}
