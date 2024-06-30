#include <stdio.h>

int mat[1024][1024];

int main() {
    int N, k, x, y;
    scanf("%d%d%d%d", &N, &k, &x, &y);

    // shift x, y to starting point
    x = (x + (k - 1)) % N, y = (y - (k - 1) + N) % N;

    for (int num = 1; num <= N * N; num++) {
        mat[x][y] = num;
        int next_x = (x - 1 + N) % N, next_y = (y + 1) % N;
        if (mat[next_x][next_y]) {
            next_x = (x + 1) % N;
            next_y = y;
        }
        x = next_x, y = next_y;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d%c", mat[i][j], " \n"[j==N-1]);
        }
    }

    return 0;
}
