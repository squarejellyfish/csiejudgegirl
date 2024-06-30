#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "merge.h"

#define max(a, b) (a) > (b) ? (a) : (b)

/*
typedef struct node {
    int data;
    struct node *next;
}Node;
*/

Node *merge(Node *list[], int K) {
    Node *head = (Node*)malloc(sizeof(Node));
    Node *prev = head;

    int flag = 1, remain = 1;
    while (remain) {
        remain = 0;
        if (flag) {
            for (int j = 0; j < K; j++) {
                if (list[j] == NULL) continue;
                remain = 1;
                prev->next = list[j];
                prev = prev->next;
                list[j] = list[j]->next;
            }
            flag = !flag;
        } else {
            for (int j = K - 1; j >= 0; j--) {
                if (list[j] == NULL) continue;
                remain = 1;
                prev->next = list[j];
                prev = prev->next;
                list[j] = list[j]->next;
            }
            flag = !flag;
        }
    }
    return head->next;
}
