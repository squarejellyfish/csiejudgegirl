#include <string.h>
#include "map.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void init(Map *map) {
    map->n = 0;
}

int map(Map *map, const int key, const char *value) {
    for (int i = 0; i < map->n; i++) {
        if (map->pairs[i].key == key) {
            strcpy(map->pairs[i].val, value);
            return 0;
        }
    }

    map->pairs[map->n].key = key;
    strcpy(map->pairs[map->n++].val, value);
    return 1;
}

int numPairs(Map *map) {
    return map->n;
}
int cmp(const void *p1, const void *p2) {
    return (*(Pair*)p1).key - (*(Pair*)p2).key;
}

void print(Map *map) {
    qsort(map->pairs, map->n, sizeof(Pair), cmp);
    printf("----- map begin -----\n");
    for (int i = 0; i < map->n; i++) {
        printf("%d %s\n", map->pairs[i].key, map->pairs[i].val);
    }
    printf("----- end       -----\n");
}

const char *getValue(Map *map, const int key) {
    for (int i = 0; i < map->n; i++) {
        if (map->pairs[i].key == key) return map->pairs[i].val;
    }
    return NULL;
}

int unmap(Map *map, int key) {
    for (int i = 0; i < map->n; i++) {
        if (map->pairs[i].key == key) {
            for (int j = i; j < map->n - 1; j++) {
                map->pairs[j] = map->pairs[j + 1];
            }
            map->n--;
            return 1;
        }
    }
    return 0;
}
int cmp_2(const void *p1, const void *p2) {
    return (*(int*)p1) - (*(int*)p2);
}

int reverseMap(Map *map, const char *value, int keys[]) {
    int n = 0;
    for (int i = 0; i < map->n; i++) {
        if (strcmp(value, map->pairs[i].val) == 0) {
            keys[n++] = map->pairs[i].key;
        }
    }
    qsort(keys, n, sizeof(int), cmp_2);
    return n;
}
