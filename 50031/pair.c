#include <stdio.h>
#include <stdlib.h>

int inc;
#ifdef INC
inc = 1;
#endif

#ifdef DEC
inc = 0;
#endif

int comp(const void* p1, const void* p2) {
    const int *a = *(const int**)p1;
    const int *b = *(const int**)p2;
    if (a[0] != b[0]) {
        return a[0] - b[0];
    }
    return a[1] - b[1];
}

int comp_2d(const void* p1, const void* p2) {
    const int *a = *(const int**)p1;
    const int *b = *(const int**)p2;
    if (a[0] != b[0]) {
        return a[0] - b[0];
    } else if (a[1] != b[1]) {
        return a[1] - b[1];
    }
    return a[2] - b[2];
}
 
void pairPrint(int numbers[], int n){
    int **new = (int**)malloc(sizeof(int*)*n);
    for (int i = 0; i < n; i++) {
        new[i] = (int*)malloc(sizeof(int)*2);
    }
    for (int i = 0; i < n; i++) {
        new[i][0] = numbers[i]; new[i][1] = i;
    }
    qsort(new, n, sizeof(new[0]), comp);
//    for (int i = 0; i < n; i++) {
//        printf("new[i] = {%d, %d}\n", new[i][0], new[i][1]);
//    }
    int **group = (int**)malloc(sizeof(int*)*(n / 2));
    for (int i = 0; i < n / 2; i++) {
        group[i] = (int*)malloc(sizeof(int)*3);
    }
    for (int i = 0; i < n / 2; i++) {
        group[i][0] = new[i][0] + new[n - i - 1][0];
        group[i][1] = new[i][1];
        group[i][2] = new[n - i - 1][1];
//        printf("group[i]: {%d, %d, %d}\n", group[i][0], group[i][1], group[i][2]);
    }
    qsort(group, n / 2, sizeof(group[0]), comp_2d);
    if (inc) {
        for (int i = 0; i < n / 2; i++) {
            int* g = group[i];
            printf("%d = numbers[%d] + numbers[%d]\n", group[i][0], (g[1] < g[2]) ? g[1] : g[2], (g[1] > g[2]) ? g[1] : g[2]);
        }
    } else {
        for (int i = n / 2 - 1; i >= 0; i--) {
            int* g = group[i];
            printf("%d = numbers[%d] + numbers[%d]\n", group[i][0], (g[1] < g[2]) ? g[2] : g[1], (g[1] > g[2]) ? g[2] : g[1]);
        }
    }
}
