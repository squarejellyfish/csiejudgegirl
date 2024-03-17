#include <stdio.h>
#include <string.h>

int main() {
    int n, m;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    int b[m];
    for (int i = 0; i < m; i++) b[i] = 0;
    for (int i = 0; i < n; i++) {
        b[a[i] % m]++;
    }
    for (int i = 0; i < m; i++) printf("%d\n", b[i]);
    return 0;
}
