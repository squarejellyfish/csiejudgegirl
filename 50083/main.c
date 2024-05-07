#include <stdio.h>

int main() {
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);
    int w;
    while (scanf("%d", &w) != EOF) {
        if (R == 0) { // first fit 
            if (N >= w) {
                N -= w;
            } else if (M >= w) {
                M -= w;
            }
        } else if (R == 1) {
            int n = N - w, m = M - w;
            if (n <= m) {
                if (n >= 0) {
                    N = n;
                } else {
                    if (m >= 0) M = m;
                }
            } else { // m smaller
                if (m >= 0) {
                    M = m;
                } else {
                    if (n >= 0) N = n;
                }
            }
        }
        printf("%d %d\n", N, M);
    }
    return 0;
}
