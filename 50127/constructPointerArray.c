#include <stdio.h>

int *addr[1048576];

void constructPointerArray(const int A[1024][1024], const int *B[1024][1024], int N) {
    // printf("N * N = %d", N *N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            addr[A[i][j]] = &A[i][j]; // addr[number] = address of number
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num = A[i][j];
            B[i][j] = addr[(num + 1) % (N * N)];
        }
    }
}
