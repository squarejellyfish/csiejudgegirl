#include <stdio.h>
#include <limits.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int sum[m], max[m], min[m];
    for (int i = 0; i < m; i++) {
        sum[i] = 0;
        max[i] = INT_MIN;
        min[i] = INT_MAX;
    }
    for (int i = 0; i < n; i++) {
        int c;
        scanf("%d", &c);
        int index = c % m;
        sum[index] += c;
        if (c > max[index]) max[index] = c;
        if (c < min[index]) min[index] = c;
    }
    for (int i = 0; i < m; i++) {
        printf("%d %d %d\n", sum[i], max[i], min[i]);
    }
    return 0;
} 
