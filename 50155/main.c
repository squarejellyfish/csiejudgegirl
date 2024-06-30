#include <stdio.h>

#define min(a, b) (a) < (b) ? (a) : (b) 
int main() {
    int a, b, c, d, e, f, g;
    scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g);

    int water = a * b * d;
    int tank_area = a * b;
    int block_area = e * f;
    int h;

    // a b c d e f g
    // 2 3 6 4 2 2 3
    if (water == 0) {
        printf("0\n");
    } else {
        int remain_area = a * b - e * f;
        if (remain_area == 0) {
            if (g >= c) h = 0;
            else h = g + d;
        } else {
            int ord_height = water / remain_area; // h if block is infinite high
            if (ord_height > g) {
                // block height + (water volume above block) / tank
                h = g + (water - (remain_area * g)) / tank_area;
            } else {
                h = ord_height;
            }
        }
        h = min(h, c);
        printf("%d\n", h);
    }


    return 0;
}
