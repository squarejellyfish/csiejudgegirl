#include <stdio.h>
#include <limits.h>

int N;
int light[4][4], current_pressed[16], shortest = INT_MAX, ans[16];
int pos[5][2] = {
             {-1, 0},
    {0, -1}, {0, 0}, {0, 1},
             {1, 0}
};
void print_light() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d%c", light[i][j], " \n"[j==N-1]);
        }
    }
}
int valid(int x, int y) {
    return x >= 0 && x < N && y >= 0 && y < N;
}
int press(int idx, int lightcount) {
    int x = idx / N, y = idx % N;
    for (int i = 0; i < 5; i++) {
        int dx = pos[i][0], dy = pos[i][1];
        if (!valid(x + dx, y + dy)) continue;

        if (light[x + dx][y + dy]) {
            light[x + dx][y + dy] = 0, lightcount--;
        } else {
            light[x + dx][y + dy] = 1, lightcount++;
        }
    }
    return lightcount;
}

void dfs(int idx, int pressed, int lightcount) {
    if (lightcount == 0) {
        if (pressed < shortest) {
            for (int i = 0; i < pressed; i++) ans[i] = current_pressed[i];
            shortest = pressed;
        }

        return;
    }
    if (pressed >= shortest) return; // pruning
    if (!valid(idx / N, idx % N)) return;

    // we press this one 
    int new_lightcount = press(idx, lightcount);
    current_pressed[pressed] = idx;
    dfs(idx + 1, pressed + 1, new_lightcount);
    press(idx, lightcount); // unpress

    // we don't press this one
    dfs(idx + 1, pressed, lightcount);

    return;
}

int main() {
    scanf("%d", &N);

    int num, lightcount = 0;
    while (scanf("%d", &num) != EOF) {
        light[num / N][num % N] = 1;
        lightcount++;
    }

    dfs(0, 0, lightcount);
    for (int i = 0; i < shortest; i++) printf("%d%c", ans[i], " \n"[i==shortest-1]);

    return 0;
}
