#include <stdio.h>
#include <limits.h>

int dist[16][16] = {0}, visited[16] = {0};
int cost = INT_MAX, N;

void solve(int city, int curr_cost, int n) {
    if (n == N - 1) {
        if (curr_cost + dist[city][0] < cost) cost = curr_cost + dist[city][0];
        return;
    }
    if (curr_cost > cost) return;

    for (int i = 1; i < N; i++) {
        if (visited[i]) continue;

        visited[i] = 1;
        solve(i, curr_cost + dist[city][i], n + 1);
        visited[i] = 0;
    }

    return;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &dist[i][j]);

    visited[0] = 1;
    solve(0, 0, 0);

    printf("%d\n", cost);

    return 0;
}
