#include "array.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(ARRAY *a,  int left, int right) {
    a->startidx = left;
    a->endidx = right;
    memset(a->arr, 0, sizeof(int));
    memset(a->isset, 0, sizeof(int));
}
int set(ARRAY *a, int index, int value) {
    if (index > a->endidx || index < a->startidx) return -2147483648;

    int i = index - a->startidx;
    a->arr[i] = value;
    a->isset[i] = 1;
    return 1;
}
int get(ARRAY *a, int index) {
    if (index > a->endidx || index < a->startidx) return -2147483648;

    int i = index - a->startidx;
    if (a->isset[i]) return a->arr[i];
    else return -2147483647;
}
void print(ARRAY *a) {
    for (int i = 0; i < a->endidx - a->startidx + 1; i++) {
        if (a->isset[i]) printf("%d\n", a->arr[i]);
        else printf("No value\n");
    }
}
void sort(ARRAY *a) {
    for (int i = 0; i < a->endidx - a->startidx; i++) {
        if (!a->isset[i]) continue;

        int min = a->arr[i];
        int idx = i;
        for (int j = i + 1; j < a->endidx - a->startidx + 1; j++) {
            if (!a->isset[j]) {
                idx = j;
                break;
            }
            if (a->arr[j] < min) {
                min = a->arr[j];
                idx = j;
            }
        }
        int tmp = a->arr[i];
        int t = a->isset[i];
        a->arr[i] = a->arr[idx];
        a->arr[idx] = tmp;
        a->isset[i] = a->isset[idx];
        a->isset[idx] = t;
    }
}
