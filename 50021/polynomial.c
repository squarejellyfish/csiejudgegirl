#include "polynomial.h"
#include <stdlib.h>
#include <stdio.h>

void init(Polynomial *poly, int coefficient[], int n) {
    poly->deg = n;
    poly->coeff = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) poly->coeff[i] = coefficient[i];
}

Polynomial add(Polynomial *poly1, Polynomial *poly2) {
    int n = (poly1->deg > poly2->deg) ? poly1->deg : poly2->deg;
    Polynomial* ret = (Polynomial*)malloc(sizeof(Polynomial));
    int* coefficient = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < poly1->deg; i++) {
        coefficient[i] += poly1->coeff[i];
    }
    for (int i = 0; i < poly2->deg; i++) {
        coefficient[i] += poly2->coeff[i];
    }
    init(ret, coefficient, n);
    return *ret;
}

Polynomial multiply(Polynomial *poly1, Polynomial *poly2) {
    int n = poly1->deg + poly2->deg;
    Polynomial* ret = (Polynomial*)malloc(sizeof(Polynomial));
    int* coefficient = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < poly1->deg; i++) {
        for (int j = 0; j < poly2->deg; j++) {
            coefficient[i+j] += poly1->coeff[i] * poly2->coeff[j];
        }
    }
    init(ret, coefficient, n);
    return *ret;
}

void print(Polynomial *poly) {
    for (int i = poly->deg - 1; i >= 0; i--) {
        int c = poly->coeff[i];
        if (c == 0) continue;
        printf("%+d", c);

        if (i == 0) continue;
        else if (i == 1) printf("x");
        else printf("x^%d", i);
    }
    printf("\n");
}
