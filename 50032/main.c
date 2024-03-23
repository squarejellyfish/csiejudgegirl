#include <stdio.h>
#include <string.h>

int board[16][16], row[16], col[16], diag_add[32], diag_sub[32];
int n, m, k;

void printboard() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c", (board[i][j]) ? 'o' : '.');
        }
        printf("\n");
    }
}

int solve(int r, int c, int count) {
    if (count == m) {
        printboard();
        return 1;
    }
    if (r == n) return 0;

    if (row[r] < k) {
        for (int i = c; i < n; i++) {
            if (board[r][i] || col[i] == k || diag_sub[r - i + (n - 1)] == k || diag_add[i + r] == k) continue;

            board[r][i] = 1;
            row[r]++; col[i]++; diag_add[r+i]++; diag_sub[r-i+(n-1)]++;
            if (solve(r, i, count + 1)) return 1;
            board[r][i] = 0;
            row[r]--; col[i]--; diag_add[r+i]--; diag_sub[r-i+(n-1)]--;
        }
    }

    return solve(r + 1, 0, count);
}

int main() {
    while (scanf("%d %d %d", &n, &m, &k) != EOF) {
        memset(board, 0, sizeof(board));
        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));
        memset(diag_add, 0, sizeof(diag_add));
        memset(diag_sub, 0, sizeof(diag_sub));
        if (!solve(0, 0, 0)) printf("N\n");
    }
    return 0;
}
