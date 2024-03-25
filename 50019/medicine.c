#include "medicine.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void init(Medicine *medicine) {
    medicine->actn = 0;
    medicine->inactn = 0;
}
int addActive(Medicine *medicine, char *name, int weight) {
    for (int i = 0; i < medicine->actn; i++) {
        if (strcmp(medicine->act[i].name, name) == 0) {
            medicine->act[i].weight += weight;
            return medicine->act[i].weight;
        }
    }
    if (medicine->actn == 2) return -1;

    strcpy(medicine->act[medicine->actn].name, name);
    medicine->act[medicine->actn++].weight = weight;
    return weight;
}

int addInactive(Medicine *medicine, char *name, int weight) {
    for (int i = 0; i < medicine->inactn; i++) {
        if (strcmp(medicine->inact[i].name, name) == 0) {
            medicine->inact[i].weight += weight;
            return medicine->inact[i].weight;
        }
    }
    if (medicine->inactn == 5) return -1;

    strcpy(medicine->inact[medicine->inactn].name, name);
    medicine->inact[medicine->inactn++].weight = weight;
    return weight;
}
int cmpIng(const void *p1, const void *p2) {
    Ingredient a = (*(Ingredient*)p1);
    Ingredient b = (*(Ingredient*)p2);
    if (a.weight != b.weight) return b.weight - a.weight;
    else return strcmp(a.name, b.name);
}

void print(Medicine *medicine) {
    int actn = medicine->actn;
    int inactn = medicine->inactn;
    qsort(medicine->act, actn, sizeof(Ingredient), cmpIng);
    qsort(medicine->inact, inactn, sizeof(Ingredient), cmpIng);
    printf("----- Active Ingredient begin   -----\n");
    for (int i = 0; i < actn; i++) {
        printf("%d %s\n", medicine->act[i].weight, medicine->act[i].name);
    }
    printf("----- end                       -----\n");
    printf("----- Inactive Ingredient begin -----\n");
    for (int i = 0; i < inactn; i++) {
        printf("%d %s\n", medicine->inact[i].weight, medicine->inact[i].name);
    }
    printf("----- end                       -----\n");
}

int totalWeight(Medicine *medicine) {
    int ret = 0;
    int actn = medicine->actn;
    int inactn = medicine->inactn;
    for (int i = 0; i < actn; i++) {
        ret += medicine->act[i].weight;
    }
    for (int i = 0; i < inactn; i++) {
        ret += medicine->inact[i].weight;
    }
    return ret;
}

char *maxIngredient(Medicine *medicine) {
    int weight = -1;
    char *name = (char*)malloc(sizeof(char)*128);
    int actn = medicine->actn;
    int inactn = medicine->inactn;
    for (int i = 0; i < actn; i++) {
        if (medicine->act[i].weight > weight) {
            weight = medicine->act[i].weight;
            strcpy(name, medicine->act[i].name);
        }
        else if (medicine->act[i].weight == weight && strcmp(medicine->act[i].name, name) < 0) {
            strcpy(name, medicine->act[i].name);
        }
    }
    for (int i = 0; i < inactn; i++) {
        if (medicine->inact[i].weight > weight) {
            weight = medicine->inact[i].weight;
            strcpy(name, medicine->inact[i].name);
        }
        else if (medicine->inact[i].weight == weight && strcmp(medicine->inact[i].name, name) < 0) {
            strcpy(name, medicine->inact[i].name);
        }
    }
    return (weight == -1) ? NULL : name;
}
