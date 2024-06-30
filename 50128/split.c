#include <stdlib.h>

void split(int A[], int *a[], int *head[], int k) {
    int len = 0;
    while (a[len]) len++; len++; // length of A
    int tail[100000];
    for (int i = 0; i < k; i++) tail[i] = -1;

    for (int i = 0; i < len; i++) {
        int r = A[i] % k;
        if (tail[r] == -1) {
            head[r] = &A[i];
        } else {
            a[tail[r]] = &A[i];
        }
        a[i] = NULL;
        tail[r] = i;
    }
}
