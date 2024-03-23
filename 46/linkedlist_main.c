#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node{
    char val;
    struct node* next;
};
typedef struct node Node;

int main() {
    char inst[7];
    Node* first = (Node*)malloc(sizeof(Node));
    first->val = '\0', first->next = NULL;
    while (scanf(" %s", inst) != EOF) {
        if (strcmp(inst, "insert") == 0) {
            char pos[10];
            scanf(" %s", pos);
            if (strlen(pos) > 1) {
                char c;
                scanf(" %c", &c);
                if (strcmp(pos, "left") == 0) {
                    Node* new = (Node*)malloc(sizeof(Node));
                    new->val = first->val, new->next = first->next;
                    first->val = c;
                    first->next = new;
                }
            }
        } else if (strcmp(inst, "delete") == 0) {
        }
    }
    Node* n = first;
    while (n != NULL) {
        printf("%c", n->val);
        n = n->next;
    }
    return 0;
}
