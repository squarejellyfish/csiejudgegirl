#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int m, n;
int mat[20][20] = {0};
int sum_rows[20] = {0}, sum_cols[20] = {0};
int used[20] = {0};

int solve_row(int row, int c) {
    if (row == m) return 1;

    if (c == n) {
        if (sum_rows[row] == 0) {
            return solve_row(row + 1, 0);
        }
    }

    for (int num = 1; num <= m * n; num++) {
        if (num > sum_cols[c] || num > sum_rows[row]) return 0;
        if (used[num]) continue;
//        printf("searching at (%d, %d) with %d\n", row, c, num);
        mat[row][c] = num;
        sum_cols[c] -= num;
        sum_rows[row] -= num;
        used[num] = 1;
        if (solve_row(row, c + 1)) return 1;
        sum_cols[c] += num;
        sum_rows[row] += num;
        used[num] = 0;
    }
    return 0;
}
void print_mat() {
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) printf("%d%c", mat[i][j], " \n"[j==n-1]);
}

int main() {
    while (scanf("%d %d", &m, &n) != EOF) {
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < m; i++) {
            scanf("%d", &sum_rows[i]); sum1 += sum_rows[i];
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &sum_cols[i]); sum2 += sum_cols[i];
        }
        memset(used, 0, sizeof(used));
        int nm = n * m;
        if (sum1 != nm*(nm+1) / 2 || sum2 != nm*(nm+1) / 2) printf("no solution\n");
        else if (solve_row(0, 0)) {
            print_mat();
        } else printf("no solution\n");
    }

    return 0;
}
