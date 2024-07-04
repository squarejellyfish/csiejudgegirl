#include "matrixOperations.h"
#include <stdio.h>

int bit(uint64_t *matrix, int x, int y) {
    return ((*matrix) & ((uint64_t)1 << (8 * x + y))) > 0;
}
int set(uint64_t *matrix, int x, int y) { // set bit to 1
    *matrix |= 1ul << (8 * x + y);
}

void printMatrix(uint64_t *matrix) {
    printf("%lu\n", *matrix);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d", bit(matrix, i, j));
        }
        printf("\n");
    }
}
void rotateMatrix(uint64_t *matrix) {
   uint64_t new = 0;
    
   for (int i = 0; i < 8; i++)  {
       for (int j = 0; j < 8; j++) {
           int b = bit(matrix, i, j);
           if (b) set(&new, j, 7 - i);
       }
   }
   *matrix = new;
}
void transposeMatrix(uint64_t *matrix) {
   uint64_t new = 0;
    
   for (int i = 0; i < 8; i++)  {
       for (int j = 0; j < 8; j++) {
           int b = bit(matrix, i, j);
           if (b) set(&new, j, i);
       }
   }
   *matrix = new;
}
