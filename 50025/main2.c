#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int friend[128][128], sub[128] = {0};
int n, m;
 
int solve(int n, int cand[], int depth) {
    if (depth == m) {
        for (int i = 0; i < m; i++) printf("%d%c", sub[i], " \n"[i==m-1]);
        return 1;
    }
    if (n < m - depth) return 0;

    int next[128], next_n = 0;
    for (int i = 1; i < n; i++) {
        if (!friend[cand[i]][cand[0]]) {
            next[next_n++] = cand[i];
        }
    }
    sub[depth] = cand[0];
    return solve(next_n, next, depth + 1) || solve(n - 1, cand + 1, depth);
}
 
int main() {
    while (scanf("%d %d", &n, &m) != EOF) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &friend[i][j]);
            }
        }
        int cand[128];
        for (int i = 0; i < n; i++) cand[i] = i;
        if (!solve(n, cand, 0)) printf("no solution\n");
    }
    return 0;
}
