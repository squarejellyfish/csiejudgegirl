#include <stdio.h>
#include <limits.h>

#define min(a, b)(((a)<(b))?(a):(b))

int N, M;
int index_table[128][128], step_count[128][128], stop[10001]; // index is also visited table
int pos[10001][2];
int moves[8][2] = {
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
};
int valid(int r, int c) {
    // check (r, c) is in bound and is not visited
    return (r >= 0 && r < N) && (c >= 0 && c < N) && (index_table[r][c] == 0);
}
int calculate_p(int r, int c) {
    int p = 0;
    for (int i = 0; i < 8; i++) { // for every possible move
        int dr = moves[i][0], dc = moves[i][1];
        if (valid(r + dr, c + dc)) p++;
    }
    return p;
}

int choose_move(int idx, int step) {
    int r = pos[idx][0], c = pos[idx][1]; // position of curr knight
    int lowest = INT_MAX, next_r = -1, next_c = -1;
    for (int i = 0; i < 8; i++) { // for every possible move
        int dr = moves[i][0], dc = moves[i][1];
        if (!valid(r + dr, c + dc)) continue;
        int p = calculate_p(r + dr, c + dc);
        if (p < lowest) {
            lowest = min(lowest, p), next_r = r + dr, next_c = c + dc;
        }
    }
    if (next_r == -1) { // no move available, stop this knight
        // printf("knight %d has no move, stopped at step %d\n", idx, step);
        stop[idx] = 1;
        return 0;
    }
    // printf("moving knight %d to (%d, %d), lowest p = %d\n", idx, next_r, next_c, lowest);
    pos[idx][0] = next_r, pos[idx][1] = next_c;
    step_count[next_r][next_c] = step;
    index_table[next_r][next_c] = idx;
    return 1;
}

int main() {
    scanf("%d%d", &N, &M);

    for (int i = 0; i < M; i++) {
        int r, c;
        scanf("%d%d", &r, &c);
        index_table[r][c] = i + 1, pos[i + 1][0] = r, pos[i + 1][1] = c;
    }

    int step = 1;
    while (1) {
        int move = 0;
        for (int i = 0; i < M; i++) {
            if (stop[i + 1]) continue; // this knight cannot move
            if (choose_move(i + 1, step)) move = 1;
        }
        step++;
        if (!move) break; // no knight moved in this step
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d%c", 10000 * index_table[i][j] + step_count[i][j], " \n"[j==N-1]);
        }
    }

    return 0;
}
