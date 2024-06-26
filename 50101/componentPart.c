#include "componentPart.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculatePrice(ComponentPart *curr, ComponentPart list[]) {
    if (curr->price)
        return curr->price;

    int ret = 0;
    for (int i = 0; i < curr->numComponent; i++) {
        ret += calculatePrice(&list[curr->componentPartList[i]], list);
    }
    curr->price = ret;
    return ret;
}
int cmp(const void* p1, const void* p2) {
    ComponentPart a = *((ComponentPart*)p1);
    ComponentPart b = *((ComponentPart*)p2);
    return strcmp(a.name, b.name);
}

void findPrice(int N,ComponentPart list[]) {
    for (int i = 0; i < N; i++) {
        int res = calculatePrice(&list[i], list);
        list[i].price = res;
    }
    qsort(list, N, sizeof(ComponentPart), cmp);
    for (int i = 0; i < N; i++) {
        ComponentPart curr = list[i];
        printf("%s %d\n", curr.name, curr.price);
    }
}
