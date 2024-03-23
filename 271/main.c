#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d", &n);
    int p1[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &p1[i]);
    }
    scanf("%d", &m);
    int p2[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &p2[i]);
    }
    int anslen = n + m - 1;
    int* ans = (int*)malloc(sizeof(int)*(n + m - 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans[i + j] += p1[i] * p2[j];
        }
    }
    for (int i = 0; i < anslen; i++) {
        printf("%d%c", ans[i], " \n"[i==anslen - 1]);
    }
    return 0;
}
