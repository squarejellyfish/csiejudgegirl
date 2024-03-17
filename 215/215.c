#include <stdio.h>

int main() {
    int s, f, t;
    scanf("%d %d %d", &s, &f, &t);
    double a = 0, b = 0, c, right;
    c = s - t;
    right = (double)f/2 - 4*c;
    if (((double)f/2) != f/2 || right < 0) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i <= t; i++) {
        int aa = t - i, bb = i;
        if (aa + 2*bb == right) {
            a = aa;
            b = bb;
            break;
        }
    }

    if (a < 0 || b < 0 || c < 0) printf("0\n");
    else printf("%.0lf\n%.0lf\n%.0lf\n", a, b, c);
    
    return 0;
}
