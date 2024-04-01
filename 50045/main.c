#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, z, xm, ym, zm, xb, yb, zb, N;
    int dirXY[3][6] = {{1, -1, 0, 0, 0, 0}, {
                        0,  0, 1,-1, 0, 0}, {
                        0,  0, 0, 0, 1,-1}};
    scanf("%d %d %d", &x, &y, &z);
    scanf("%d %d %d %d %d %d", &xm, &ym, &zm, &xb, &yb, &zb);
    scanf("%d", &N);

    int sucked = 0;
    for (int i = 0; i < N; i++) {
        int dir;
        scanf("%d", &dir);
        x += dirXY[0][dir - 1];
        y += dirXY[1][dir - 1];
        z += dirXY[2][dir - 1];
        int dist_mine = abs(xm - x) + abs(ym - y) + abs(zm - z);
        int dist_hole = abs(xb - x) + abs(yb - y) + abs(zb - z);
        if (dist_mine < 10) {
            x = xm;
            y = ym;
            z = zm;
            break;
        } else if (dist_hole < 10 && !sucked) {
            x = xb;
            y = yb;
            z = zb;
            sucked = 1;
        }
        if ((i + 1) % 5 == 0) printf("%d %d %d\n", x, y, z);
    }

    return 0;
}
