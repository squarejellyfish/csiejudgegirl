#include "matrix_multiplication.h"

void matrix_multiplication(int N, int** ptrA, int M, int** ptrB, int S, int *result) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ptrA[2][i] != ptrB[1][j]) continue;
            int row = ptrA[1][i], col = ptrB[2][j];
            result[row * S + col] += ptrA[0][i] * ptrB[0][j];
        }
    }
}
