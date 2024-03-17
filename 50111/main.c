#include <stdio.h>

#define MAXN 1024

int N, E;
int adj[MAXN][MAXN] = {0}, next[MAXN] = {0};

int dfs(int step, int curr, int head) {
    if (step == N) {
        if (adj[curr][0]) {
            next[curr] = -1;
            return 1;
        }
        return 0;
    }
    for (int p = -1, c = head; c != -1; p = c, c = next[c]) {
        if (!adj[curr][c]) continue;
        if (c == head) {
            if (dfs(step + 1, c, next[c])) {
                next[curr] = c;
                return 1;
            }
        } else {
            next[p] = next[c];
            if (dfs(step + 1, c, head)) {
                next[curr] = c;
                return 1;
            }
            next[p] = c;
        }
    }
    return 0;
}

int main() {
    scanf("%d%d", &N, &E);
    for (int e = 0; e < E; e++) {
        int a, b;
        scanf("%d%d", &a, &b);
        adj[a][b] = 1, adj[b][a] = 1;
    }
    for (int i = 0; i < N; i++) {
        next[i] = i + 1;
    }
    next[N - 1] = -1;

    if (!dfs(1, 0, next[0])) {
        printf("NO SOLUTION\n");
    } else {
        for (int i = 0; i != -1; i = next[i]) printf("%d ", i);
        printf("0\n");
    }

    return 0;
}
