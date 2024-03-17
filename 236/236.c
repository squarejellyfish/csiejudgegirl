#include <stdio.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int curr, last;
    scanf("%d", &last);
    while (scanf("%d", &curr) != EOF) {
        last = last * curr / gcd(last, curr);
    }
    printf("%d\n", last);
    return 0;
}
