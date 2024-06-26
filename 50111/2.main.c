#include <stdio.h>

int N, E;
int adj[1024][1024], visited[1024], route[1024];

int dfs(int depth, int curr) {
    if (depth == N) {
        if (adj[curr][0]) {
            for (int i = 0; i < depth; i++) printf("%d ", route[i]);
            return 1;
        }
        return 0;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i] || !adj[curr][i]) continue; // visited 要放前面，不然會TLE（幹真的很靠背）
        if (depth == N - 1 && !adj[0][i]) continue; // 這樣加了一點速

        visited[i] = 1, route[depth] = i;
        if (dfs(depth + 1, i)) return 1;
        visited[i] = 0;
    }
    return 0;
}

int main() {
    scanf("%d %d", &N, &E);

    for (int i = 0; i < E; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][b] = 1, adj[b][a] = 1;
    }

    visited[0] = 1, route[0] = 0;
    if (dfs(1, 0)) {
        printf("0\n");
    } else printf("NO SOLUTION\n");

    return 0;
}
