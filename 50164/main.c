#include <stdio.h>

int arr[1024][1024];
int ans = 0;

void check_dice(int row, int col) {
    int seen[7] = {0};
    for (int c = col; c < col + 4; c++) { // check row has dup or not
        int num = arr[row][c];
        if (seen[num]) return;
        else seen[num] = 1;
    }
    // check row add up to 7
    if ((arr[row][col] + arr[row][col + 2] != 7) || (arr[row][col + 1] + arr[row][col + 3] != 7))
        return;
    // now we search
    for (int up = col; up < col + 4; up++) {
        int upnum = arr[row - 1][up];
        if (seen[upnum]) continue;
        seen[upnum] = 1;
        for (int down = col; down < col + 4; down++) {
            int downnum = arr[row + 1][down];
            if (!seen[downnum] && upnum + downnum == 7)
                ans++;
        }
        seen[upnum] = 0;
    }
}

int main() {
    int R, C;
    scanf("%d%d", &R, &C);

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    for (int i = 1; i < R - 1; i++) {
        for (int j = 0; j < C - 3; j++) {
            check_dice(i, j);
        }
    }
    printf("%d\n", ans);

    return 0;
}
