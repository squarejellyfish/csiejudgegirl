#include <stdio.h>                                                                              
 
typedef unsigned long long int ull;
 
void printBlock(unsigned long long int *block) {
    ull filter = 1;
    int i = 0;
    while (i < 64) {
        printf("%lld", (*block & (filter << i)) >> i);
        if ((i + 1) % 8 == 0) printf("\n");
        i++;
    }
}
 
void initialize(unsigned long long int *block, int row, int column, int size) {
    *block = 0ull;
    ull ret = 0, single_row = (1ull << size) - 1;
    for (int i = 0; i < size; i++) {
        ret |= single_row;
        single_row <<= 8;
    }

    *block = (ret << (row * 8 + column));
}
 
int moveLeft(unsigned long long int *block) {
    if (*block & 0x0101010101010101) return 0;
    *block >>= 1;
    return 1;
}
 
int moveRight(unsigned long long int *block) {
    if (*block & 0x8080808080808080) return 0;
    *block <<= 1;
    return 1;
}
 
int moveUp(unsigned long long int *block) {
    if (*block & 0x00000000000000FF) return 0;
    *block >>= 8;
    return 1;
}
 
int moveDown(unsigned long long int *block) {
    if (*block & 0xFF00000000000000) return 0;
    *block <<= 8;
    return 1;
}
