#include "chasing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void chasing(int **A[], int a, int *B[], int b, int C[], int c) {
    for (int i = 0; i < a; i++) A[i] = NULL;
    for (int i = 0; i < a; i++) B[i] = NULL;

    char line[64], *s[5];
    while (fgets(line, 64, stdin) != NULL) {
        s[0] = strtok(line, " ");
        for (int i = 1; i < 5; i++) {
            s[i] = strtok(NULL, " ");
        }
        // if line.split() is != 4
        if (s[0] == NULL || s[1] == NULL || s[2] == NULL || s[3] == NULL || s[4] != NULL) {
            printf("0\n");
            continue;
        }
        // if is not a one char string
        char *arr1 = s[0], *arr2 = s[2];
        if (strlen(arr1) != 1 || strlen(arr2) != 1) {
            printf("0\n");
            continue;
        }
        // if contains non-digit
        int valid = 1;
        int len = strlen(s[1]);
        for (int i = 0; i < len; i++) {
            if (!isdigit(s[1][i])) {
                valid = 0;
                break;
            }
        }
        if (!valid) {
            printf("0\n");
            continue;
        }
        valid = 1;
        len = strlen(s[3]);
        for (int i = 0; i < len - 1; i++) {
            if (!isdigit(s[3][i])) {
                valid = 0;
                break;
            }
        }
        if (!valid) {
            printf("0\n");
            continue;
        }
        int n = atoi(s[1]), m = atoi(s[3]);

        if (arr1[0] == 'A' && arr2[0] == 'B') {
            if (n >= a || m >= b || n < 0 || m < 0) {
                printf("0\n");
                continue;
            }

            A[n] = &B[m];
            printf("1\n");
        }
        else if (arr1[0] == 'B' && arr2[0] == 'C') {
            if (n >= b || m >= c || n < 0 || m < 0) {
                printf("0\n");
                continue;
            }

            B[n] = &C[m];
            printf("1\n");
        }
        else printf("0\n");
    }
}
