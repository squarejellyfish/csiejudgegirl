#include "constructTable.h"
#include <stdlib.h>
#include <stdio.h>

int ***constructTable(int A[], int B[]) {
    int ***first = (int***)malloc(sizeof(int**)*128);
    int a = 0, b = 0;
    while (A[a]) {
        int curr_size = A[a];
        int **curr_sec = (int**)malloc(sizeof(int*)*(curr_size + 1));
        for (int i = 0; i < curr_size; i++) {
            curr_sec[i] = &B[b];
            while (B[b]) b++;
            b++;
        }
        curr_sec[curr_size] = NULL;
        first[a] = curr_sec;
        a++;
    }
    first[a] = NULL;

    return first;
}
