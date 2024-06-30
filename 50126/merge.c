#include <stdio.h>
// #include "merge.h"

void merge(int A[], int B[], int* a[], int* b[]){
    int i = 0, j = 0;
    int n = 0, m = 0;
    // get length
    while (a[n] != NULL) n++;
    n++;
    while (b[m] != NULL) m++;
    m++;

    while (i < n && j < m) {
        if (A[i] < B[j]) { // A[i] is the current smallest
            if (i == n - 1) a[i] = &B[j]; // if we at the last one, means B[j] is largest
            else a[i] = (B[j] < A[i + 1]) ? &B[j] : &A[i + 1]; // choose the smaller one between B[j] and A[i + 1]
            i++;
        } else { // B[j] is the current smallest
            if (j == m - 1) b[j] = &A[i]; // we at the last one, means A[i] is largest
            else b[j] = (A[i] < B[j + 1]) ? &A[i] : &B[j + 1];
            j++;
        }
    }
}
