#include <stdio.h>
#include <stdlib.h>

int grid[300000][2];

int main() {
    int n, m, x, y;
    while (scanf("%d %d %d %d", &n, &m, &x, &y) != EOF) {
        // constructing generic solution
        int start = 0;
        for (int i = 0; i < m; i++) {
            grid[i][0] = 0;
            grid[i][1] = i;
            if (x == 0 && y == i) start = i;
        }
        int yy = m - 1, xx = 1, i = m;
        while (yy >= 0) {
            if (yy % 2 == 1) {
                grid[i][0] = xx;
                grid[i][1] = yy;
                xx++;
            } else {
                grid[i][0] = xx;
                grid[i][1] = yy;
                xx--;
            }
            if (grid[i][0] == x && grid[i][1] == y) start = i;
            if (xx == n || xx == 0) {
                yy--;
                xx += (xx == n) ? -1 : 1;
            }
            i++;
        }
        for (int i = start; i < n * m; i++) {
            printf("%d %d\n", grid[i][0], grid[i][1]);
        }
        for (int i = 0; i <= start; i++) {
            printf("%d %d\n", grid[i][0], grid[i][1]);
        }
    }


    return 0;
}
