#include <stdio.h>
#include <limits.h>

int friend[16][16], apart[16], live[16];
int ans = INT_MAX, N, M;

void dfs(int where, int dist) {
    if (dist >= ans) return;
    if (where == N) {
//        printf("where = %d, dist = %d\n", where, dist);
//        for (int i = 0; i < N; i++) printf("%d%c", apart[i], " \n"[i == N - 1]);
        if (dist < ans) {
            ans = dist;
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (live[i]) continue; // person already living

        int next_dist = dist;
        for (int j = 0; j < where; j++) {
            if (!friend[apart[j]][i]) continue;
            next_dist += where - j;
        }
        apart[where] = i, live[i] = 1;
        dfs(where + 1, next_dist);
        apart[where] = 0, live[i] = 0;
    }
    return;
}

int main() {
    scanf("%d %d", &N, &M);

    for (int i = 0; i < N; i++) live[i] = 0;
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        friend[a][b] = 1, friend[b][a] = 1;
    }
    dfs(0, 0);
    printf("%d\n", ans);

    return 0;
}
