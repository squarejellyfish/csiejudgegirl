#include <stdio.h>

int K, grid[4][4] = {{0}};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = { 0, 1, 0,-1};

int solve(int r, int c, int last, int step) {
//    printf("current searching: \n");
    int w = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
//            printf("%d%c", grid[i][j], " \n"[j==3]);
            if (grid[i][j] != (i*4 + (j+1)) % 16) w++;
        }
    }
    if (!w) return 1;
    if (!step || (w - 1) > K) return 0;

    for (int m = 0; m < 4; m++) {
        // avoiding going back
        if ((m + 2) % 4 == last) continue;
        int nextr = r + dr[m], nextc = c + dc[m];
        if (nextr > 3 || nextr < 0 || nextc > 3 || nextc < 0) continue;

        grid[r][c] = grid[nextr][nextc], grid[nextr][nextc] = 0;
        if (solve(nextr, nextc, m, step - 1)) return 1;
        grid[nextr][nextc] = grid[r][c], grid[r][c] = 0;
    }
    return 0;
}

int main() {
    while (scanf("%d", &K) != EOF) {
        int r, c;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &grid[i][j]);
                if (grid[i][j] == 0) {
                    r = i, c = j;
                }
            }
        }
        printf("%d\n", solve(r, c, -1, K));
    }
    return 0;
}
