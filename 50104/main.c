#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct member
{
    char name[64];
    struct member *left;
    struct member *right;
};
typedef struct member Member;

typedef struct club
{
    char name[64];
    struct club *left;
    struct club *right;
    Member *members;
} Club;

Member *insert_member(Member *root, char name[64])
{
    Member *current;
    if (root == NULL)
    {
        current = (Member *)malloc(sizeof(Member));
        assert(current != NULL);
        strcpy(current->name, name);
        current->left = NULL;
        current->right = NULL;
        return (current);
    }
    if (strcmp(name, root->name) < 0)
        root->left = insert_member(root->left, name);
    else
        root->right = insert_member(root->right, name);
    return (root);
}
Club *insert_club(Club *root, char name[64], char mem[64])
{
    Club *current;
    if (root == NULL) {
        current = (Club *)malloc(sizeof(Club));
        assert(current != NULL);
//        printf("malloc success\n");
        strcpy(current->name, name);
 //       printf("assign name success\n");
        current->left = NULL;
        current->right = NULL;
        current->members = NULL;
  //      printf("set NULL success\n");
        current->members = insert_member(current->members, mem);
   //     printf("insert members success\n");
        return (current);
    }
    int diff = strcmp(name, root->name);
    if (diff == 0) {
        root->members = insert_member(root->members, mem);
    } else if (diff < 0) {
        root->left = insert_club(root->left, name, mem);
    } else {
        root->right = insert_club(root->right, name, mem);
    }
    return (root);
}
Club *find_club(Club *root, char name[64]) {
    if (root == NULL) return NULL;
    int diff = strcmp(name, root->name);
    if (diff == 0) {
        return root;
    } else if (diff < 0) {
        return find_club(root->left, name);
    } else {
        return find_club(root->right, name);
    }
}
int find_member(Member *root, char name[64]) {
    if (root == NULL) return 0;
    if (strcmp(name, root->name) == 0) {
        return 1;
    } else if (strcmp(name, root->name) < 0) {
        return find_member(root->left, name);
    } else {
        return find_member(root->right, name);
    }
}

int main(void)
{
    Club *clubs = NULL;
    int K, Q;
    int ins;
    char mem[64], club[64];
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d %s %s", &ins, mem, club);
        clubs = insert_club(clubs, club, mem);
    }
    scanf("%d", &Q);
    for (int i = 0; i < Q; i++) {
        scanf("%d", &ins);
        if (ins == 0) {
            scanf(" %s", club);
            Club *res = find_club(clubs, club);
            if (res != NULL) printf("%s\n", res->members->name);
            else printf("None\n");
        } else if (ins == 1) {
            scanf(" %s %s", mem, club);
            Club *res = find_club(clubs, club);
            if (res == NULL) printf("-1\n");
            else {
                int r = find_member(res->members, mem);
                printf("%d\n", r);
            }
        }
    }
    return 0;
}
