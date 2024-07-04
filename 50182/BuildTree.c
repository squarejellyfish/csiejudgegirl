#include "BuildTree.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct Node
{
    int val;
    struct Node *left, *right;
}Node; */
Node *cut(Node *list) {
    if (list == NULL) return NULL;
    int length = 0;
    Node *tmp = list;
    while (tmp) tmp = tmp->left, length++;

    int first;
    if (length % 2 == 0) first = length / 2;
    else first = (length + 1) / 2;

    Node *f = list;
    for (int i = 0; i < first - 1; i++) f = f->left;
    Node *ret = f->left; // this is the rest of the list
    f->left = NULL; // cut it
    return ret;
}
void print_node(Node *n) {
    if (!n) printf("null\n");
    else printf("node val = %d\n", n->val);
}

Node* BuildTree(Node* list1, Node* list2) {
    if (list1 == NULL && list2 == NULL) {
        return NULL;
    }
    else if (list1 == NULL) {
        return list2;
    }
    else if (list2 == NULL) {
        return list1;
    }
    else {
        Node *root;
        if (list1->val < list2->val) {
            root = list1;
            list1 = list1->left;
        } else {
            root = list2;
            list2 = list2->left;
        }
        // get the rest of list1, list2
        Node *rest1 = cut(list1);
        Node *rest2 = cut(list2);
//        print_node(list1);
//        print_node(list2);
//        print_node(rest1);
//        print_node(rest2);

        root->left = BuildTree(list1, list2);
        root->right = BuildTree(rest1, rest2);

        return root;
    }
}
