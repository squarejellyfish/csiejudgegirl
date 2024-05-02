#include <stdio.h>
#include <limits.h>

int main() {
    int N, incomplete = 0, max = INT_MIN, min = INT_MAX, num;
    while (scanf("%d", &N) != EOF) {
        max = INT_MIN, min = INT_MAX;
        for (int i = 0; i < N; i++) {
            if (scanf("%d", &num) == EOF) {
                incomplete = 1;
                break;
            }
            if (num > max) max = num;
            if (num < min) min = num;
        }
        if (incomplete) break;
        printf("%d\n", max);
    }
    if (incomplete) printf("%d\n", min);
    
    return 0;
}
