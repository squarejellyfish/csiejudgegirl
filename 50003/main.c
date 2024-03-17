#include <stdio.h>
#include <stdlib.h>
 
int max(int a, int b) {
    return (a > b) ? a : b;
}
int min(int a, int b) {
    return (a > b) ? b : a;
}
 
int main() {
    int L, X, Y, n, fucked = 0, l;
    int graphic[100][100] = {{0}};
    scanf("%d%d%d", &L, &X, &Y);
    int x1, y1, x2, y2;
    for(l = 0; l < L && !fucked; l++) {
        scanf("%d", &n);
        scanf("%d%d", &y1, &x1);
        for (int p = 1; p < n; p++) {
            scanf("%d%d", &y2, &x2);
            if ((x1 == x2) || (y1 == y2) || (abs(x1 - x2) == abs(y1 - y2))) {
                // do graphic
                if (x1 == x2) {
                    int end = max(y1, y2), start = min(y1, y2);
                    for (int i = start; i <= end; i++) {
                        graphic[x1][i] = 1;
                    }
                } else if (y1 == y2) {
                    int end = max(x1, x2), start = min(x1, x2);
                    for (int i = start; i <= end; i++) {
                        graphic[i][y1] = 1;
                    }
                } else {
                    int dx, dy, step = abs(x2 - x1);
                    dx = (x2 - x1 > 0) ? 1 : -1;
                    dy = (y2 - y1 > 0) ? 1 : -1;
                    while (step != -1) {
                        graphic[x1 + dx*step][y1 + dy*step] = 1;
                        step--;
                    }
                }
            } else {
                fucked = 1;
                break;
            }
            x1 = x2, y1 = y2;
        }
    }
    if (fucked) {
        printf("ERROR %d %d\n", l, n);
    } else {
        for (int i = X - 1; i >= 0; i--) {
            for (int j = 0; j < Y; j++) {
                printf("%d", graphic[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
