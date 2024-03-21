#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int friend[128][128], sub[128] = {0};
int n, m;

int solve(int curr, int depth) {
//    printf("searching %d, depth = %d\n", curr, depth);
    if (depth == m) {
        for (int i = 0; i < m; i++) printf("%d%c", sub[i], " \n"[i==m-1]);
        return 1;
    }
    for (int c = curr + 1; c <= n - (m - depth); c++) {
        int fucked = 0;
        for (int d = 0; d < depth; d++) {
            if (friend[sub[d]][c]) {
                fucked = 1;
                break;
            }
        }
        if (!fucked) {
            sub[depth] = c;
            if (solve(c, depth + 1)) return 1;
        }
    }
    return 0;
}

int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &friend[i][j]);
            }
        }
        if (m > n) {
            printf("no solution\n");
            continue;
        }
        int found = 0;
        for (int i = 0; i < n - m + 1; i++) {
            sub[0] = i;
            if (solve(i, 1)) {
                found = 1;
                break;
            }
        }
        if (!found) printf("no solution\n");
    }
    return 0;
}
