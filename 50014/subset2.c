#include "subset.h"
 
int subset(int numbers[], int n, int K, int S){
    if (!S) {
        if (!K) return 1;
        else return 0;
    }
    if (K <= 0) return 0;

    for (int i = 0; i < n; i++) {
        if (subset(numbers + i + 1, n - i - 1, K - numbers[i], S - 1)) return 1;
    }
    return 0;
}
