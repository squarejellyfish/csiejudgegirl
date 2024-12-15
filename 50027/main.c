#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fs.h"

// typedef struct {
//     int balance;
//     char name[128];
//     int gender;
// } Account;

int valid(Account* acc) {
    if (acc->balance < 0 || acc->gender < 0 || acc->gender > 1) return 0;
    int len = strlen(acc->name);
    for (int i = 0; i < len; i++) {
        if (!(acc->name[i] == ' ' || isalpha(acc->name[i]))) return 0;
    }
    return 1;
}
int cmp(const void* p1, const void* p2) {
    Account* a = (Account*)p1, *b = (Account*)p2;
    return strcmp(a->name, b->name);
}

int main(void) {
    char file_name[64], out_name[64];
    scanf("%s %s", file_name, out_name);

    FILE *file = fopen(file_name, "rb");
    FILE *out = fopen(out_name, "wb");

    int n = 0;
    Account accs[1024] = {0};

    Account acc;
    while (fread(&acc, sizeof(Account), 1, file)) {
        if (valid(&acc)) accs[n++] = acc;
    }

    qsort(accs, n, sizeof(Account), cmp);
    fwrite(accs, sizeof(Account), n, out);
    fclose(file);
    fclose(out);

    return 0;
}
