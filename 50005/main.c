#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, k, m, d, diff;
    scanf("%d %d %d %d", &n, &k, &m, &d);
    int mat1[n][n], mat2[k][k];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat1[i][j]);
    for (int i = 0; i < k; i++)
        for (int j = 0; j < k; j++)
            scanf("%d", &mat2[i][j]);

    int match = 0, ans[2] = {-1, -1};
    for (int i = 0; i < n - k + 1; i++) {
        for (int j = 0; j < n - k + 1; j++) {
            int mismatch = 0, no = 0, s1 = 0, s2 = 0;
            for (int di = 0; di < k && mismatch <= m; di++) {
                for (int dj = 0; dj < k && mismatch <= m; dj++) {
                    if (mat1[i+di][j+dj] != mat2[di][dj]) {
                        mismatch++;
                        s1 += mat1[i+di][j+dj], s2 += mat2[di][dj];
                        if (mismatch > m) no = 1;
                    }
                }
            }
            if (abs(s1 - s2) > d) no = 1;
            // printf("mismatch = %d, diff = %d\n", mismatch, diff);
            if (!no) {
                ans[0] = i, ans[1] = j;
            }
        }
    }
    printf("%d %d\n", ans[0], ans[1]);

    return 0;
}
