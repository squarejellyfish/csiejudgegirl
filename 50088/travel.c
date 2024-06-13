#include "travel.h"
#include <stdio.h>
#include <limits.h>

void travel(int map[1024][1024], int N, int M, int A_r, int A_c, int B_r, int B_c, int directionA[], int directionB[]) {
    int visited[N][M];
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) visited[i][j] = 0;
    int seq[3][3] = {
        {5, 3, 6},
        {1, -1, 0},
        {7, 2, 4}
    };
    
    int A = 1, B = 1, ac = 0, bc = 0;
    while(A || B) {
//        printf("A: (%d, %d)\nB: (%d, %d)\n", A_r, A_c, B_r, B_c);
        if (A_r == B_r && A_c == B_c) {
            directionA[ac] = -1;
            directionB[bc] = -1;
            break;
        }
        if (visited[A_r][A_c]) {
            directionA[ac] = -1;
            A = 0;
        }
        if (visited[B_r][B_c]) {
            directionB[bc] = -1;
            B = 0;
        }
        visited[A_r][A_c] = 1;
        visited[B_r][B_c] = 1;

        if (A) {
            int next = -1, nr = 0, nc = 0;
            for (int dr = -1; dr <= 1; dr++) {
                int next_r = A_r + dr;
                if (next_r < 0 || next_r >= N) continue;
                for (int dc = -1; dc <= 1; dc++) {
                    int next_c = A_c + dc;
                    if (next_c < 0 || next_c >= M) continue;
                    if (map[next_r][next_c] > next) {
                        next = map[next_r][next_c];
                        nr = dr; nc = dc;
                    }
                }
            }
            directionA[ac++] = seq[nr + 1][nc + 1];
            A_r += nr; A_c += nc;
        }
        if (B) {
            int next = INT_MAX, nr = 0, nc = 0;
            for (int dr = -1; dr <= 1; dr++) {
                int next_r = B_r + dr;
                if (next_r < 0 || next_r >= N) continue;
                for (int dc = -1; dc <= 1; dc++) {
                    int next_c = B_c + dc;
                    if (next_c < 0 || next_c >= M) continue;
                    if (map[next_r][next_c] < next) {
                        next = map[next_r][next_c];
                        nr = dr; nc = dc;
                    }
                }
            }
            directionB[bc++] = seq[nr + 1][nc + 1];
            B_r += nr; B_c += nc;
        }
        if (directionA[ac] == -1) A = 0;
        if (directionB[bc] == -1) B = 0;
    }
}
