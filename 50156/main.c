#include <stdio.h>

#define max(a, b) (a) > (b) ? (a) : (b)

int main() {
    int a, b, v, w, x, y, z;
    scanf("%d%d%d%d%d%d%d", &a, &b, &v, &w, &x, &y, &z);

    int dis = 0, p = 1;
    // compare v/a & w/a + 1 to dis/p
    int odd_p = (a % 2 == 1) ? a : a + 1, even_p = (a % 2 == 0) ? a : a + 1;
    if (v * p > odd_p * dis) {
        dis = v, p = odd_p;
    }
    if (w * p > even_p * dis) {
        dis = w, p = even_p;
    }
    // compare x / b, x / b + 1, x / b + 2 to dis/p
    int zero, one, two;
    for (int i = b; i < b + 3; i++) {
        if (i % 3 == 0) zero = i;
        if (i % 3 == 1) one = i;
        if (i % 3 == 2) two = i;
    }
    if (x * p > zero * dis) {
        dis = x, p = zero;
    }
    if (y * p > one * dis) {
        dis = y, p = one;
    }
    if (z * p > two * dis) {
        dis = z, p = two;
    }

    printf("%d\n", p);

    return 0;
}
