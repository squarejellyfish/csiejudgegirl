#include <stdio.h>

int n;
int seat[1024][20][5];
int lscar = 0, lsrow = 0, lscol = 0; // last single
int ldcar = 0, ldrow = 0, ldcol = 0; // last double

int find_single() {
    for (int car = lscar; car < n; car++) {
        int start = (car == lscar) ? lsrow : 0;
        for (int row = start; row < 20; row++) {
            for (int col = 0; col < 5; col++) {
                if (!seat[car][row][col]) {
                    seat[car][row][col] = 1;
                    lscar = car, lsrow = row, lscol = col;
                    return 1;
                }
            }
        }
    }
    return 0;
}
int find_double() {
    for (int car = ldcar; car < n; car++) {
        int start = (car == ldcar) ? ldrow : 0;
        for (int row = start; row < 20; row++) {
            for (int col = 0; col < 4; col++) {
                if (col == 2) continue; // skip aisle
                if (!seat[car][row][col] && !seat[car][row][col + 1]) {
                    seat[car][row][col] = 1, seat[car][row][col + 1] = 1;
                    ldcar = car, ldrow = row, ldcol = col;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    scanf("%d", &n);

    int r;
    while (scanf("%d", &r) != EOF) {
        if (r == 1) {
            if (find_single()) printf("%d %d %d\n", lscar + 1, lsrow + 1, lscol + 1);
        } else {
            if (find_double()) printf("%d %d %d %d %d %d\n", ldcar + 1, ldrow + 1, ldcol + 1, ldcar + 1, ldrow + 1, ldcol + 2);
            else { // split to two single
                if (find_single()) {
                    printf("%d %d %d", lscar + 1, lsrow + 1, lscol + 1);
                    if (find_single()) printf(" %d %d %d\n", lscar + 1, lsrow + 1, lscol + 1);
                    else printf("\n");
                }
            }
        }
    }

    return 0;
}
