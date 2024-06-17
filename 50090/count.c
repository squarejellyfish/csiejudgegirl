#include "count.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Pointer {
    int *addr;
    int count;
} Pointer;

int cmp(const void *p1, const void *p2) {
    Pointer a = *((Pointer*)p1);
    Pointer b = *((Pointer*)p2);
    if (a.count == b.count) {
        return *a.addr - *b.addr;
    } 
    return a.count - b.count;
}

void count(int **p[]) {
    Pointer pointers[512];
    int pc = 0;
    int i = 0;
    while (p[i]) {
        int *intptr = *p[i], found = 0;
        for (int j = 0; j < pc; j++) {
            if (pointers[j].addr == intptr) {
                pointers[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            pointers[pc].addr = intptr;
            pointers[pc++].count = 1;
        }
        i++;
    }
    qsort(pointers, pc, sizeof(Pointer), cmp);
    for (int i = 0; i < pc; i++) {
        printf("%d %d\n", *pointers[i].addr, pointers[i].count);
    }
}
