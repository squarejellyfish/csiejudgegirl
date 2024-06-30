#include <stdio.h>

int a, b, c, d, e;

int C(int x) {
    int ret = 0;
    while (!(x >= d && x <= e)) {
        x = (a * x + b) % c;
        ret ++;
    }
    return ret;
}

int main() {
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);

    int num1 = -1, num2 = -1, num3 = -1, num;
    int c1 = -1, c2 = -1, c3 = -1, found = 0;

    while (scanf("%d", &num) != EOF) {
        num1 = num2, num2 = num3, num3 = num; 
        c1 = c2, c2 = c3, c3 = C(num);

        if (c1 == -1 || c2 == -1) continue;
        int csum = c1 + c2 + c3, n, n1, n2;
        if (c1 < c2 && c1 < c3) {
            n = c1, n1 = (c2 < c3) ? c2 : c3, n2 = (c3 > c2) ? c3 : c2;
        }
        else if (c2 < c1 && c2 < c3) {
            n = c2, n1 = (c1 < c3) ? c1 : c3, n2 = (c3 > c1) ? c3 : c1;
        }
        else {
            n = c3, n1 = (c1 < c2) ? c1 : c2, n2 = (c2 > c1) ? c2 : c1;
        }
        if (n1 == n + 1 && n2 == n1 + 1) { // is consecutive
            // printf("\nfound: %d %d %d\n", c1, c2, c3);
            found = 1;
            break;
        }
    }
    if (found) {
        printf("%d %d %d\n", num1, num2, num3);
    } else printf("Not found\n");

    return 0;
}
