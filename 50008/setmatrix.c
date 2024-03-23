#include <stdio.h>
#include "setmatrix.h"
 
void processSetMatrix(int ***ptr) {
    int printed = 0;
    int i = 0;
    while (ptr[i] != NULL) {
        int j = 0;
        while (ptr[i][j] != NULL) {
            int k = 0;
            while (ptr[i][j][k] != 0) {
                if (!printed) {
                    printf("%d", ptr[i][j][k]);
                    printed = 1;
                } else {
                    printf(" %d", ptr[i][j][k]);
                }
                k++;
            }
            j++;
        }
        i++;
    }
}
