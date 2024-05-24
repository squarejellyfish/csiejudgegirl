#include <stdio.h>

int map[512][512] = {{0}};
int N, M, L, W, O, tx = 0, ty = 0;

int hit(int x, int y) {
    int count = 0;
    for (int i = y; i < y + L; i++) 
        for (int j = x; j < x + W; j++) 
            if (map[i][j] == 2) {
                count++;
            }
//    printf("tank at %d, %d hit %d obs\n", x, y, count);
    if (count < 2) {
        for (int i = y; i < y + L; i++) 
            for (int j = x; j < x + W; j++) 
                if (map[i][j] == 2) map[i][j] = 0;
        return 0;
    }
    return 1;
}

int main() {
    scanf("%d %d %d %d", &N, &M, &L, &W);
    scanf("%d", &O);
    for (int i = 0; i < O; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        map[y][x] = 2;
    }

    int op;
    while (scanf("%d", &op) != EOF) {
        if (op == 0) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    if ((i >= ty && i < ty + L) && (j >= tx && j < tx + W)) {
                        printf("1");
                    }
                    else printf("%d", map[i][j]);
                }
                printf("\n");
            }
        } else if (op == 1) {
            if (!(tx + 1 + W > M) && !hit(tx + 1, ty)) {
                tx++;
            }
        } else if (op == 2) {
            if (!(ty + 1 + L > N) && !hit(tx, ty + 1)) {
                ty++;
            }
        } else if (op == 3) {
            if (!(tx - 1 < 0) && !hit(tx - 1, ty)) {
                tx--;
            }
        } else if (op == 4) {
            if (!(ty - 1 < 0) && !hit(tx, ty - 1)) {
                ty--;
            }
        } else if (op == 5) {
            if (!(tx + 1 + W > M) && !(ty + 1 + L > N) && !hit(tx + 1, ty + 1)) {
                tx++;
                ty++;
            }
        }
    }
    return 0;
}
