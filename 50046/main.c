#include <stdio.h>
#include <string.h>

int main() {
    int h[16][16];
    int n, m, T;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) h[i][j] = 1;
    T = 2*m*m;
    for (int q = 0; q < n; q++) {
        int curr[16][16];
        int expect, sum = 0;
        scanf("%d", &expect);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &curr[i][j]);
                sum += curr[i][j] * h[i][j];
            }
        }
        if (sum < T && expect == 1) { // reject but ans is accept
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    if (curr[i][j]) h[i][j] *= 2;
                }
            }
        } else if (sum >= T && expect == 0) { // accept but ans is reject
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < m; j++) {
                    if (curr[i][j]) {
                        h[i][j] = (h[i][j] / 2 == 0) ? 1 : h[i][j] / 2;
                    }
                }
            }
        }
    }
//    printf("h:");
//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < m; j++) {
//            printf("%d%c", h[i][j], " \n"[j==m-1]);
//        }
//    }

    int Q;
    scanf("%d", &Q);
    for (int q = 0; q < Q; q++) {
        int curr[16][16], sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &curr[i][j]);
                sum += curr[i][j] * h[i][j];
            }
        }
        if (sum < T) printf("0\n");
        else printf("1\n");
    }
    return 0;
}
