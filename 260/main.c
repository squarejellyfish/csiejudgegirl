#include <stdio.h>
#include <string.h>

#define MAXN 128

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    char result[MAXN], curr[MAXN];
    int len, len_curr;
    scanf(" %s", result);
    while (scanf(" %s", curr) != EOF) {
        len = strlen(result), len_curr = strlen(curr);
        int i, j, start = max(len - len_curr, 0), fucked;
        i = start, fucked = 1;
        for (i; i < len && fucked; i++) {
            j = 0;
            if (result[i] == curr[j]) {
                int ii = i + 1;
                j++;
                while (1) {
                    if (result[ii] == '\0') {
                        fucked = 0;
                        break;
                    }
                    if (result[ii] != curr[j]) break;
                    ii++, j++;
                }
            }
        }
        while (curr[j] != '\0') {
            result[len] = curr[j];
            len++, j++;
        }
        result[len] = '\0';
    }
    printf("%s\n", result);
    return 0;
}
