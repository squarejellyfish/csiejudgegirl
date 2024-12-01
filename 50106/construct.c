#include "construct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef struct Node{
//     char name[16];
//     int height;
//     int weight;
//     struct Node *left, *right;
// } Node;

Node *insert_bs_tree(Node *root, char name[16], int height, int weight)
{
  Node *current;
  if (root == NULL) {
    current = (Node*)malloc(sizeof(Node));
    strcpy(current->name, name);
    current->height = height;
    current->weight = weight;
    current->left = NULL;
    current->right = NULL;
    return(current);
  }
#ifdef WEIGHT
  if (weight < root->weight) 
    root->left = insert_bs_tree(root->left, name, height, weight);
  else 
    root->right =insert_bs_tree(root->right,name, height, weight);
#else
  if (height < root->height) 
    root->left = insert_bs_tree(root->left, name, height, height);
  else 
    root->right =insert_bs_tree(root->right,name, height, height);
#endif
  return(root);
}

Node *ConstructBSTree(int N, char name[][16], int height[], int weight[]) {
    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        root = insert_bs_tree(root, name[i], height[i], weight[i]);
    }
    return root;
}
