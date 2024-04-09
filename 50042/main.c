#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int max = -1, maxi, maxj;
    for (int i = 0; i < n; i++) {
        int g = -1, gg = -1, gj, ggj;
        for (int j = 0; j < m; j++) {
            int curr;
            scanf("%d", &curr);
            if (curr >= max) {
                max = curr;
                maxi = i + 1; maxj = j + 1;
            }
            if (curr >= gg) {
                g = gg;
                gg = curr;
                gj = ggj; ggj = j + 1;
            }
            else if (curr >= g) {
                g = curr;
                gj = j + 1;
            }
        }
        printf("%d %d\n", ggj, gj);
    }
    printf("%d %d\n", maxi, maxj);

    return 0;
}
