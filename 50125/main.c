#include <stdio.h>
#include "findLength.h"
#define MAXN 256

#define max(a, b) (a) > (b) ? (a) : (b)
/*
int findLength (int array[][256], int N, int r, int c, int dr, int dc);
*/

int array[MAXN][MAXN];
int direction[4][2] = {{1,0}, {1,1}, {0,1}, {-1,1}};

int main () {
    int N, r, c;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &array[i][j]);

    // row 
    int longest = 0;
    for (int i = 0; i < N; i++) {
        longest = max(longest, findLength(array, N, i, 0, 0, 1));
    }
    // col
    for (int j = 0; j < N; j++) {
        longest = max(longest, findLength(array, N, 0, j, 1, 0));
    }
    // diag 1
    for (int j = 0; j < N; j++) {
        longest = max(longest, findLength(array, N, 0, j, 1, 1));
        longest = max(longest, findLength(array, N, j, 0, 1, 1));
    }
    // diag 2
    for (int j = 0; j < N; j++) {
        longest = max(longest, findLength(array, N, j, 0, -1, 1));
        longest = max(longest, findLength(array, N, N - 1, N - 1 - j, -1, 1));
    }
    printf("%d\n", longest);

    return 0;
}

