#include <stdio.h>

int main() {
    int arrive, a, b, A = 0, B = 0;
    while (scanf("%d %d %d", &arrive, &a, &b) != EOF) {
        if (arrive <= A) {
            A += a;
        } else {
            A = arrive + a;
        }
        if (A <= B) {
            B += b;
        } else {
            B = A + b;
        }
        printf("%d\n", B);
    }
    
    return 0;
}
