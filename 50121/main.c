#include <stdio.h>

int map[512][512];
int N, M, energy;

int count_and_move_down(int x, int y) {
    int cons = 0;
    for (int j = x; j < N; j++) {
        if (map[j][y]) {
            if (j == N - 1) return 0;
            cons += map[j][y];
        }
        else {
            if (energy - cons >= 0) {
                for (int k = j; k >= x; k--) {
                    map[k][y] = map[k - 1][y];
                }
                return energy - cons;
            } else return 0; // didn't move
        }
    }
    return cons; // should not be here
}
int count_and_move_up(int x, int y) {
    int cons = 0;
    for (int j = x; j >= 0; j--) {
        if (map[j][y]) {
            if (j == 0) return 0;
            cons += map[j][y];
        } else {
            if (energy - cons >= 0) {
                for (int k = j; k <= x; k++) {
                    map[k][y] = map[k + 1][y];
                }
                return energy - cons;
            } else return 0; // didn't move
        }
    }
    return cons;
}
int count_and_move_left(int x, int y) {
    int cons = 0;
    for (int j = y; j >= 0; j--) {
        if (map[x][j]) {
            if (j == 0) return 0;
            cons += map[x][j];
        } else {
            if (energy - cons >= 0) {
                for (int k = j; k <= y; k++) {
                    map[x][k] = map[x][k + 1];
                }
                return energy - cons;
            } else return 0; // didn't move
        }
    }
    return cons; // fucked
}
int count_and_move_right(int x, int y) {
    int cons = 0;
    for (int j = y; j < M; j++) {
        if (map[x][j]) {
            if (j == M - 1) return 0;
            cons += map[x][j];
        }
        else {
            if (energy - cons >= 0) {
                for (int k = j; k >= y; k--) {
                    map[x][k] = map[x][k - 1];
                }
                return energy - cons;
            } else return 0; // didn't move
        }
    }
    return cons; // should not be here
}

void print_map() {
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < M; j++) 
            printf("%d%c", map[i][j], " \n"[j==M-1]);
}

int main() {
    int x, y, O;
    scanf("%d%d%d%d%d%d", &N, &M, &x, &y, &energy, &O);
    map[x][y] = energy;

    for (int i = 0; i < O; i++) {
        int a, b, weight;
        scanf("%d%d%d", &a, &b, &weight);
        map[a][b] = weight;
    }

    int op;
    while (scanf("%d", &op) != EOF) {
        if (op == 0) {
            print_map();
        } else if (op == 1) {
            if (y + 1 >= M) continue;
            if (!map[x][y + 1]) { // no obstacle in way
                map[x][y + 1] = map[x][y];
                map[x][y] = 0;
                y++;
            } else {
                int consume = count_and_move_right(x, y + 1);
                if (consume) { // we move
                    map[x][y] = 0;
                    y++;
                    energy = consume;
                    map[x][y] = energy;
                }
            }
        } else if (op == 2) {
            if (x + 1 >= N) continue;
            if (!map[x + 1][y]) { // no obstacle in way
                map[x + 1][y] = map[x][y];
                map[x][y] = 0;
                x++;
            } else {
                int consume = count_and_move_down(x + 1, y);
                if (consume) {
                    map[x][y] = 0;
                    x++;
                    energy = consume;
                    map[x][y] = energy;
                }
            }
        } else if (op == 3) {
            if (y - 1 < 0) continue;
            if (!map[x][y - 1]) {
                map[x][y - 1] = map[x][y];
                map[x][y] = 0;
                y--;
            } else {
                int consume = count_and_move_left(x, y - 1);
                if (consume) {
                    map[x][y] = 0;
                    y--;
                    energy = consume;
                    map[x][y] = energy;
                }
            }
        } else if (op == 4) {
            if (x - 1 < 0) continue;
            if (!map[x - 1][y]) {
                map[x - 1][y] = map[x][y];
                map[x][y] = 0;
                x--;
            } else {
                int consume = count_and_move_up(x - 1, y);
                if (consume) {
                    map[x][y] = 0;
                    x--;
                    energy = consume;
                    map[x][y] = energy;
                }
            }
        }
//        printf("debug: \n");
//        print_map();
    }

    return  0;
}
