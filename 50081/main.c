#include <stdio.h>

int main() {
    int N, M, x = 0, y = 0;
    scanf("%d %d", &N, &M);
    printf("%d\n%d\n", x, y);

    int op;
    while (scanf("%d", &op) != EOF) {
        if (op % 5 == 0) continue;
        else if (op % 5 == 1) {
            if (x + op < N) x += op;
            else continue;
        }
        else if (op % 5 == 2) {
            if (x - op >= 0) x -= op;
            else continue;
        }
        else if (op % 5 == 3) {
            if (y + op < M) y += op;
            else continue;
        }
        else if (op % 5 == 4) {
            if (y - op >= 0) y -= op;
            else continue;
        }
        printf("%d\n%d\n", x, y);
    }

    return 0;
}
