#include "merge.h"
#include <stdio.h>
#include <stdlib.h>

/*
typedef struct node {
    int data;
    struct node *next;
}Node;
*/
void zigzag(Node *list[], int K, Node *prev) {
    int remains = 1, flag = 1;
    while (remains) {
        remains = 0;
        for (int i = (flag) ? 0 : K - 1; (flag) ? (i < K) : (i >= 0); i += (flag) ? 1 : -1) {
            if (list[i] == NULL) continue;
            remains = 1;
            prev->next = list[i];;
            prev = prev->next;
            list[i] = list[i]->next;
        }
        flag = !flag;
    }
}

void topdown(Node *list[], int K, Node *prev) {
    int remains = 1, flag = 1;
    while (remains) {
        remains = 0;
        for (int i = 0; i < K; i++) {
            if (list[i] == NULL) continue;
            remains = 1;
            prev->next = list[i];;
            prev = prev->next;
            list[i] = list[i]->next;
        }
        flag = !flag;
    }
}
void bottomup(Node *list[], int K, Node *prev) {
    int remains = 1, flag = 1;
    while (remains) {
        remains = 0;
        for (int i = K - 1; i >= 0; i--) {
            if (list[i] == NULL) continue;
            remains = 1;
            prev->next = list[i];;
            prev = prev->next;
            list[i] = list[i]->next;
        }
        flag = !flag;
    }
}

Node *merge(Node *list[], int K) {
    Node *head = (Node*)malloc(sizeof(Node));
    Node *prev = head;

#ifdef ZIGZAG
    zigzag(list, K, prev);
#endif
#ifdef TOPDOWN
    topdown(list, K, prev);
#endif
#ifdef BOTTOMUP
    bottomup(list, K, prev);
#endif
    return head->next;
}
