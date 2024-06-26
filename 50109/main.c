#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Auth {
    char name[16];
    int cited;
} Auth;

Auth auths[20000];

int cmp(const void* p1, const void *p2) {
    Auth a = *((Auth*)p1);
    Auth b = *((Auth*)p2);
    if (strcmp(a.name, b.name) == 0) return b.cited - a.cited;
    return strcmp(a.name, b.name);
}

int main() {
    char name[16];
    int cited, N = 0;
    while (scanf(" %s %d", name, &cited) != EOF) {
        strcpy(auths[N].name, name);
        auths[N++].cited = cited;
    }
    qsort(auths, N, sizeof(Auth), cmp);

    int prev = 0, H = 0;
    for (int i = 0; i < N; i++) {
        Auth curr = auths[i];
        if (i == 0) { // first case
            if (curr.cited >= H + 1) H++;
            continue;
        }
        if (strcmp(curr.name, auths[prev].name) != 0) { // only printf when we encounter new name
            printf("%s %d\n", auths[prev].name, H); // and we print the prev encounter name
            H = 0; // reset H-index
            prev = i; // set prev to this new encounter name
        }
        if (curr.cited >= H + 1) H++;
    }
    printf("%s %d\n", auths[prev].name, H);

    return 0;
}
