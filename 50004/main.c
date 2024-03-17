#include <stdio.h>

int main() {
    int a[4][4];
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 4; j++)
            scanf("%d", &a[i][j]);

    int move, fucked = 1, temp;
    while (scanf("%d", &move) != EOF) {
        if (move > 15 || move < 1) continue;
        temp = -1;
        for (int i = 0; i < 4 && temp == -1; i++) {
            for (int j = 0; j < 4 && temp == -1; j++) {
                if (a[i][j] != move) continue;

                if (i - 1 >= 0 && a[i-1][j] == 0) {
                    temp = a[i][j], a[i][j] = a[i-1][j], a[i-1][j] = temp;
                } else if (j - 1 >= 0 && a[i][j-1] == 0) {
                    temp = a[i][j], a[i][j] = a[i][j-1], a[i][j-1] = temp;
                } else if (j + 1 < 4 && a[i][j+1] == 0) {
                    temp = a[i][j], a[i][j] = a[i][j+1], a[i][j+1] = temp;
                } else if (i + 1 < 4 && a[i+1][j] == 0) {
                    temp = a[i][j], a[i][j] = a[i+1][j], a[i+1][j] = temp;
                }
            }
        }
        fucked = 0;
        if (temp != -1) {
            for (int i = 0; i < 4 && fucked == 0; i++) 
                for (int j = 0; j < 4 && fucked == 0; j++) 
                    if (a[i][j] != (4 * i + j + 1) % 16) fucked = 1;
        } else continue;
        if (!fucked) {
            // printf("fucked, %d\n");
            break;
        }
    }
    for (int i = 0; i < 4; i++) 
        for (int j = 0; j < 4; j++) 
            printf("%d%c", a[i][j], " \n"[j==3]);
    if (!fucked && temp != -1) {
        printf("1 %d\n", temp);
    } else {
        printf("0\n");
    }
    return 0;
}
