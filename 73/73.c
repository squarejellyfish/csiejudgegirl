#include <stdio.h>

int main() {
    int n, a[3] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        a[num % 3]++;
    }
    printf("%d %d %d\n", a[0], a[1], a[2]);
    return 0;
}
