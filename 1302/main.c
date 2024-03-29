#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int game[9][9];
int **valid_row, **valid_col, **valid_gon;
 
int valid(int i, int j, int n) {
    if (valid_row[i][n - 1] && valid_col[j][n - 1] && valid_gon[(i/3)*3 + (j/3)][n - 1]) return 1;
    else return 0;
}
 
void fill(int i, int j, int n) {
    valid_row[i][n - 1] = 0;
    valid_col[j][n - 1] = 0;
    valid_gon[(i/3)*3 + (j/3)][n - 1] = 0;
}
 
void unfill(int i, int j, int n) {
    valid_row[i][n - 1] = 1;
    valid_col[j][n - 1] = 1;
    valid_gon[(i/3)*3 + (j/3)][n - 1] = 1;
}
 
int solve(int r, int c) {
    if (r == 9) return 1;
 
    for (int i = r; i < 9; i++) {
        int left = (i > r) ? 0 : c;
        for (int j = left; j < 9; j++) {
            if (game[i][j] != 0) continue;
            // printf("now at %d, %d ", i, j);
            // try each number
            int yes = 0;
            for (int n = 1; n <= 9; n++) {
                if (valid(i, j, n)) {
                    game[i][j] = n;
                    fill(i, j, n);
                    // printf("searching %d\n", n);
                    int nexti = i, nextj = j + 1;
                    if (nextj == 9) {
                        nexti = i + 1;
                        nextj = 0;
                    }
                    yes = solve(nexti, nextj);
                    if (yes) return 1;
 
                    game[i][j] = 0;
                    unfill(i, j, n);
                }
            }
            if (!yes) return 0;
        }
    }
 
    return 0;
}
 
int main() {
    valid_row = (int**)malloc(sizeof(int*)*9);
    valid_col = (int**)malloc(sizeof(int*)*9);
    valid_gon = (int**)malloc(sizeof(int*)*9);
    for (int i = 0; i < 9; i++) {
        valid_row[i] = (int*)malloc(sizeof(int)*9);
        valid_col[i] = (int*)malloc(sizeof(int)*9);
        valid_gon[i] = (int*)malloc(sizeof(int)*9);
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            valid_row[i][j] = 1;
            valid_col[i][j] = 1;
            valid_gon[i][j] = 1;
        }
    }
    for (int i = 0; i < 9; i++) {
        char row[10];
        scanf(" %s", row);
        for (int j = 0; j < 9; j++) {
            game[i][j] = row[j] - '0';
            if (game[i][j] != 0) {
                valid_row[i][game[i][j] - 1] = 0;
                valid_col[j][game[i][j] - 1] = 0;
                valid_gon[(i / 3)*3 + (j / 3)][game[i][j] - 1] = 0;
            }
        }
    }
 
    int yes = solve(0, 0);
    if (yes) {
        printf("Solved Successfully!\n");
        printf("---------------------\n");
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                printf("%d ", game[i][j]);
                if (j == 2 || j == 5) printf("| ");
            }
            printf("\n");
            if (i % 3 == 2) printf("---------------------\n");
        }
    } else {
        printf("No answer\n");
    }
 
    return 0;
}
