#include "game_of_cell.h"
#include <string.h>
#include <stdio.h>

int dir[2][8] = {{-1, -1, -1, 0, 0, 1, 1, 1}, {-1, 0, 1, -1, 1, -1, 0, 1}};
int next[3][9] = {{0, 0, 0, 2, 0, 0, 0, 0, 0},
                  {1, 1, 2, 1, 1, 1, 1, 1, 1},
                  {0, 0, 2, 2, 1, 1, 1, 1, 1}};

void game_of_cell(int grid[50][50],int outcome[50][50],int N) {
    int g[2][50][50];
    for (int i = 0; i < 50; i++) for (int j = 0; j < 50; j++) g[0][i][j] = grid[i][j];
    for (int i = 0; i < 50; i++) for (int j = 0; j < 50; j++) g[1][i][j] = 0;
    int n = 0;
    for (n; n < N; n++) {
        for (int i = 0; i < 50; i++) {
            for (int j = 0; j < 50; j++) {
                int neighbors = 0, curr = n % 2, other = (curr) ? 0 : 1;
                for (int d = 0; d < 8; d++) {
                    if (i + dir[0][d] < 0 || i + dir[0][d] == 50 || j + dir[1][d] < 0 || j + dir[1][d] == 50) continue;
                    neighbors += g[curr][i + dir[0][d]][j + dir[1][d]] / 2;
                }
                g[other][i][j] = next[g[curr][i][j]][neighbors];
//                printf("(%d, %d) has %d neighbors\n", i, j, neighbors);
            }
        }
//        memcpy(grid, new_grid, sizeof(int) * 2500);
//        for (int i = 0; i < 50; i++) for (int j = 0; j < 50; j++) grid[i][j] = new_grid[i][j];
    }
    memcpy(outcome, g[n % 2], sizeof(int) * 2500);
//    memcpy(outcome, grid, sizeof(int) * 2500);
//    for (int i = 0; i < 50; i++) for (int j = 0; j < 50; j++) outcome[i][j] = grid[i][j];
}
