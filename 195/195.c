#include <stdio.h>
#include <stdlib.h>

int game[3][3] = {{0}};

int check_win() {
    // row
    for (int i = 0; i < 3; i++) {
        if (!game[i][0]) continue;
        if (game[i][0] == game[i][1] && game[i][1] == game[i][2]) return game[i][0];
    }
    // col
    for (int i = 0; i < 3; i++) {
        if (!game[0][i]) continue;
        if (game[0][i] == game[1][i] && game[1][i] == game[2][i]) return game[0][i];
    }
    // diact
    if ((game[0][0] == game[1][1] && game[1][1] == game[2][2]) || (game[0][2] == game[1][1] && game[1][1] == game[2][0])) {
        if (game[1][1] != 0) return game[1][1];
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int n, ans = 0;
    scanf("%d", &n);
    int i = 0, c = 0;
    while (i != n && c < 9 && ans == 0) {
        int x, y;
        scanf("%d %d", &x, &y);
        i++;
        if (x > 2 || x < 0 || y > 2 || y < 0) continue;
        if (game[x][y] != 0) continue;
        if (c % 2 == 1) {
            game[x][y] = 2;
        } else {
            game[x][y] = 1;
        }
        ans = check_win();
        c++;
    }

    if (ans == 0) printf("There is a draw.\n");
    else if (ans == 1) printf("Black wins.\n");
    else if (ans == 2) printf("White wins.\n");

    return 0;
}
