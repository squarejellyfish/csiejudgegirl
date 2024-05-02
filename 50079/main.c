#include <stdio.h>

int main() {
    int total, center;
    int a, b;
    scanf("%d %d", &a, &b);
    total = ((a + b) * (b - a + 1)) / 2;
    printf("%d\n", total);
    printf("%d\n", total - ((a - 1) + (b - 3)) * (b - a - 1) / 2);
    return 0;
}
