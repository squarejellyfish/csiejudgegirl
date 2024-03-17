#ifndef _POLYNOMIAL_H
#define _POLYNOMIAL_H
 
/*
    define structure polynomial
*/
typedef struct Polynomial_ {
    int deg;
    int* coeff;
} Polynomial;
 
void init(Polynomial *poly, int coefficient[], int n);
Polynomial add(Polynomial *poly1, Polynomial *poly2); 
Polynomial multiply(Polynomial *poly1, Polynomial *poly2);
void print(Polynomial *poly);
 
#endif
