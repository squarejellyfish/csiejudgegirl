#include <stdio.h>

#define max(a,b) ((a > b) ? a : b)

int mat[1024][1024];

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // check row
    int longest = 0;
    for (int i = 0; i < N; i++) {
        int cons = 0;
        for (int j = 0; j < N; j++) {
            if (mat[i][j]) cons++;
            else {
                longest = max(cons, longest);
                cons = 0;
            }
        }
        longest = max(cons, longest);
    }
    // check col
    for (int i = 0; i < N; i++) {
        int cons = 0;
        for (int j = 0; j < N; j++) {
            if (mat[j][i]) cons++;
            else {
                longest = max(cons, longest);
                cons = 0;
            }
        }
        longest = max(cons, longest);
    }
    // diag top left to bottom right
    for (int i = N - 1; i >= 0; i--) {
        int x = 0, y = i;
        int cons = 0;
        while (x < N && y < N) {
            if (mat[x][y]) cons++;
            else {
                longest = max(cons, longest);
                cons = 0;
            }
            x++, y++;
        }
        longest = max(cons, longest);
    }
    for (int i = 1; i < N; i++) {
        int x = i, y = 0;
        int cons = 0;
        while (x < N && y < N) {
            if (mat[x][y]) cons++;
            else {
                longest = max(cons, longest);
                cons = 0;
            }
            x++, y++;
        }
        longest = max(cons, longest);
    }

    printf("%d", longest);

    return 0;
}
