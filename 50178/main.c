#include <stdio.h>
#include <limits.h>

int N;
int adj[8][8];
int longest = INT_MIN, current[8], ans[8], visited[8];

void dfs(int curr, int chosen) {
    if (adj[curr][0]) { // has a path to 0, compare
        if (chosen > longest) {
            for (int i = 0; i < chosen; i++) ans[i] = current[i];
            longest = chosen;
        }
    }

    // search city 1 to N - 1
    for (int i = 1; i < N; i++) {
        int next = i;
        if (visited[next]) continue;
        if (!adj[next][curr]) continue;

        current[chosen] = next, visited[next] = 1;
        dfs(next, chosen + 1);
        visited[next] = 0;
    }
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    dfs(0, 0);
    for (int i = 0; i < longest; i++) printf("%d%c", ans[i], " \n"[i==longest-1]);

    return 0;
}
