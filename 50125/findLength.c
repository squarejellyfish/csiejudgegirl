#include "findLength.h"

#define max(a, b) (a) > (b) ? (a) : (b)

int findLength (int array[][256], int N, int r, int c, int dr, int dc) {
    int cons = 0, ret = -1;
    while (r >= 0 && r < N && c >= 0 && c < N) {
        if (array[r][c]) cons++;
        else {
            ret = max(cons, ret);
            cons = 0;
        }
        r += dr, c += dc;
    }
    ret = max(cons, ret);
    return ret;
}
