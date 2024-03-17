#include "bingo.h"

typedef unsigned long long int ll;


int bingo(const unsigned long long int *board, int *rowColumn) {
    ll row = 0xFF00000000000000;
    for (int i = 0; i < 8; i++) {
        if (!((*board & row) ^ row)) {
            *rowColumn = i;
            return 1;
        }
        row >>= 8;
    }

    ll col = 0x8080808080808080;
    for (int i = 0; i < 8; i++) {
        ll check = *board & col;
        if (!((*board & col) ^ col)) {
            *rowColumn = i;
            return 2;
        }
        col >>= 1;
    }

    ll D1 = 0x8040201008040201;
    ll D2 = 0x0102040880402010;
    if (!((*board & D1) ^ D1)) {
        *rowColumn = 0;
        return 3;
    } else if (!((*board & D2) ^ D2)) {
        *rowColumn = 1;
        return 3;
    }
    return 0;
}



