#include <stdint.h>
#include <stdio.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    int a[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            int curr = a[i][j];
            int top = (i - 1 < 0) ? INT32_MIN : a[i - 1][j];
            int left = (j - 1 < 0) ? INT32_MIN : a[i][j - 1];
            int right = (j + 1 == c) ? INT32_MIN : a[i][j + 1];
            int bottom = (i + 1 == r) ? INT32_MIN : a[i + 1][j];
            if (curr > top && curr > left && curr > right && curr > bottom)
                printf("%d\n", a[i][j]);
        }
    }
    return 0;
}
