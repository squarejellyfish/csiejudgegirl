#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int pre, a, b;
} Frac;

int gcd(int a, int b) {
    int temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {
    int op;
    Frac f1, f2;
    scanf("%d %d %d", &f1.pre, &f1.a, &f1.b);
    scanf("%d", &op);
    scanf("%d %d %d", &f2.pre, &f2.a, &f2.b);
    f1.a += abs(f1.pre) * f1.b;
    f2.a += abs(f2.pre) * f2.b;
    if (f1.pre < 0) f1.a *= -1;
    if (f2.pre < 0) f2.a *= -1;
    f1.pre = 0, f2.pre = 0;

    Frac new;
    new.pre = 0;
    if (op == 0) {
        new.a = f1.a * f2.b + f1.b * f2.a;
        new.b = f1.b * f2.b;
    } else if (op == 1) {
        new.a = f1.a * f2.b - f1.b * f2.a;
        new.b = f1.b * f2.b;
    } else if (op == 2) {
        new.a = f1.a * f2.a;
        new.b = f1.b * f2.b;
    } else if (op == 3) {
        new.a = f1.a * f2.b;
        new.b = f1.b * f2.a;
    }
    int g = gcd(new.a, new.b);
    new.a /= g, new.b /= g;
    if (abs(new.a) >= abs(new.b)) {
        new.pre += new.a / new.b;
        new.a = abs(new.a % new.b);
    }
    printf("%d\n%d\n%d\n", new.pre, new.a, abs(new.b));
    return 0;
}
