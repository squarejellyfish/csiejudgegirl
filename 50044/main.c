#include <stdio.h>

int main() {
    int G[1024][1024] = {{0}};
    int n, m, sx, sy, ex, ey, Q, len = 1;
    int dirXY[2][4] = {{1, -1, 0, 0}, {0, 0, 1, -1}};
    scanf("%d %d", &n, &m);
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    
    // from tail to head
    if (sx == ex && ey < sy) for (int i = ey; i <= sy; i++) G[sx][i] = len++;
    if (sx == ex && sy < ey) for (int i = ey; i >= sy; i--) G[sx][i] = len++;
    if (sy == ey && ex < sx) for (int i = ex; i <= sx; i++) G[i][sy] = len++;
    if (sy == ey && sx < ex) for (int i = ex; i >= sx; i--) G[i][sy] = len++;

    scanf("%d", &Q);
    int t = len--;
    for (int q = 0; q < Q; q++) {
        int dir;
        scanf("%d", &dir);
        if (sx + dirXY[0][dir] < 0 || sx + dirXY[0][dir] == n || sy + dirXY[1][dir] < 0 || sy + dirXY[1][dir] == m || t - G[sx + dirXY[0][dir]][sy + dirXY[1][dir]] < len) {
            break;
        }
        sx += dirXY[0][dir];
        sy += dirXY[1][dir];
        G[sx][sy] = t++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (t - G[i][j] <= len && G[i][j]) putchar('1');
            else putchar('0');
        }
        puts("");
    }

    return 0;
}
