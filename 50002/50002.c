#include <stdio.h>
#include <stdlib.h>

int ***boards, **count;
int n;

int count_neighbors(int board, int r, int c) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        if (r + i < 0 || r + i == n) continue;
        for (int j = -1; j <= 1; j++) {
            if (c + j < 0 || c + j == n || (r + i == r && c + j == c)) continue;
            if (boards[board][r+i][c+j] == 1) count++;
        }
    }
    return count;
}

int main() {
    int k, step = 0;
    scanf("%d %d", &n, &k);

    boards = (int***)malloc(sizeof(int**)*2);
    boards[0] = (int**)malloc(sizeof(int*)*n);
    boards[1] = (int**)malloc(sizeof(int*)*n);
    count = (int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++) {
        boards[0][i] = (int*)malloc(sizeof(int)*n);
        boards[1][i] = (int*)malloc(sizeof(int)*n);
        count[i] = (int*)malloc(sizeof(int)*n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &boards[0][i][j]);
            if (boards[0][i][j] == 1) count[i][j]++;
        }
    }
    // printf("\n");

    while (step != k) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int b = step % 2;
                int neighbors = count_neighbors(b, i, j);
                // printf("%d%c", neighbors, " \n"[j==n-1]);
                if (boards[b][i][j] == 1) {
                    if (step != 0) count[i][j]++;
                    if (neighbors < 2 || neighbors > 3) boards[!b][i][j] = 0;
                    else boards[!b][i][j] = 1;
                } else {
                    if (neighbors == 3) boards[!b][i][j] = 1;
                    else boards[!b][i][j] = 0;
                }
            }
        }
        step++;
    }
    // count last time
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (boards[step % 2][i][j] == 1) count[i][j]++;
        }
    }

    int r, c, max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d%c", boards[step % 2][i][j], " \n"[j==n-1]);
            // printf("%d%c", count[i][j], " \n"[j==n-1]);
            if (count[i][j] >= max) {
                r = i;
                c = j;
                max = count[i][j];
            }
        }
    }
    printf("%d %d\n", r + 1, c + 1);

    return 0;
}



