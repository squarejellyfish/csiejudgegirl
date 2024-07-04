#include <stdio.h>

int R, C;
int r, c; // head of row, tail of col
int arr[600][600];

void print_arr() {
    for (int i = r; i < R; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d%c", arr[i][j], " \n"[j==c-1]);
        }
    }
}

void fold_down(int k) {
    for (int i = 0; i < k; i++) {
        int row = r + i;
        for (int j = 0; j < c; j++) {
            int trow = r + k * 2 - 1 - i; 
            arr[trow][j] += arr[row][j];
        }
    }
    r += k;
}
void fold_left(int k) {
    for (int j = 0; j < k; j++) {
        int col = c - 1 - j;
        for (int i = r; i < R; i++) {
            int tcol = c - k * 2 + j;
            arr[i][tcol] += arr[i][col];
        }
    }
    c -= k;
}
void fold_diag(int k) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k - i - 1; j++) {
            int row = r + i;
            int col = c - (k - i) + 1 + j;
            int trow = row + 1 + j, tcol = c - k + i;
            arr[trow][tcol] += arr[row][col];
            arr[row][col] = 0;
        }
    }
}

int main() {
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    r = 0, c = C;

    int op, k;
    while (scanf("%d%d", &op, &k) != EOF) {
        if (op == 1) {
            fold_down(k);
        } else if (op == 2) {
            fold_left(k);
        } else if (op == 3) {
            fold_diag(k);
        }
    }
    print_arr();

    return 0;
}
