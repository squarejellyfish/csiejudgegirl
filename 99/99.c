#include <stdio.h>
#include <stdlib.h>

typedef struct Player_ {
    char name[64];
    int** bingo;
    int* col;
    int* row;
    int won;
} Player;

Player* players;
int n, m;

int main() {
    scanf("%d %d", &n, &m);
    players = (Player*)malloc(sizeof(Player)*n);
    for (int p = 0; p < n; p++) {
        scanf(" %s", players[p].name);
        players[p].bingo = (int**)malloc(sizeof(int*)*2);
        players[p].col = (int*)malloc(sizeof(int*)*(m*m+1));
        players[p].row = (int*)malloc(sizeof(int*)*(m*m+1));
        players[p].won = 0;
        for (int i = 0; i < 2; i++) {
            players[p].bingo[i] = (int*)malloc(sizeof(int)*(m+1)); 
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                int num;
                scanf("%d", &num);
                players[p].row[num] = i;
                players[p].col[num] = j;
            }
        }
    }

    int ans = 0, someonewon = 0;
    for (int _ = 0; _ < m*m && !someonewon; _++) {
        int num;
        scanf("%d", &num);
        for (int p = 0; p < n; p++) {
            int r = players[p].row[num];
            int c = players[p].col[num];
            players[p].bingo[0][r]++;
            players[p].bingo[1][c]++;
            if (r == c) players[p].bingo[0][m]++;
            if (r == m - 1 - c) players[p].bingo[1][m]++;
            if (players[p].bingo[0][r] == m || players[p].bingo[1][c] == m || players[p].bingo[0][m] == m || players[p].bingo[1][m] == m) {
                ans = num;
                players[p].won = 1;
                someonewon = 1;
            }
        }
    }
    printf("%d", ans);
    for (int p = 0; p < n; p++) {
        if (players[p].won) printf(" %s", players[p].name);
    }
    
    return 0;
}
