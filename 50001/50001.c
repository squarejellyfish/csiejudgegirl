#include <stdio.h>
#include <stdlib.h>

int abs(int n) {
    if (n < 0) return n * -1;
    return n;
}

int main() {
    int a, b, c, d, e;
    int p, q, r, s;
    int x, y, F;
    long long gold = 0;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    scanf("%d%d%d%d", &p, &q, &r, &s);
    scanf("%d%d%d", &x, &y, &F);

    while (1) {
        if ((x == p && y == q) || (x == r && y == s)) {
            if (x == p) {
                x = r;
                y = s;
            } else {
                x = p;
                y = q;
            }
        } else {
            gold += abs(c*x + d*y) % e;
        }

        if (F == 0) break;

        int move = abs(a*x + b*y) % 4;
        if (move == 0) y++;
        if (move == 1) x++;
        if (move == 2) y--;
        if (move == 3) x--;
        F--;
    }

    printf("%lld\n%d %d\n", gold, x, y);

    return 0;
}
