#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

int N, M;
int friend[16][16] = {{0}};
int dist = INT_MAX, seat[16], seated[16] = {0};
int ans[16];

void solve(int idx, int curr_dist) {
    if (idx == N) {
        if (curr_dist < dist) {
            dist = curr_dist;
            for (int i = 0; i < N; i++) ans[i] = seat[i];
        }
        return;
    }

    for (int i = 0; i < N; i++) {
        if (seated[i]) continue;

        // calculate dist
        int next_dist = curr_dist;
        for (int j = 0; j < idx; j++) {
            if (friend[i][seat[j]] && idx - j > next_dist) {
                next_dist = idx - j;
                break;
            }
        }
        if (next_dist > dist) return; // pruning
                                      
        seated[i] = 1; seat[idx] = i;
        solve(idx + 1, next_dist);
        seated[i] = 0;
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        char a, b;
        scanf(" %c %c", &a, &b);
        friend[a - 'A'][b - 'A'] = 1;
        friend[b - 'A'][a - 'A'] = 1;
    }

    solve(0, -1);
    printf("%d\n", dist);
    for (int i = 0; i < N; i++) printf("%c%c", ans[i] + 'A', " \n"[i==N-1]);

    return 0;
}
