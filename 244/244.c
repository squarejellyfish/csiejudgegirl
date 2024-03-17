#include <stdio.h>

int main() {
    char special[3][9], price[3][9];
    for (int i = 0; i < 3; i++) scanf(" %s", special[i]);
    for (int i = 0; i < 3; i++) scanf(" %s", price[i]);
    int sum = 0;
    char curr[9];
    int p[9] = {0, 0, 0, 200, 1000, 4000, 10000, 40000, 200000};
    while (scanf(" %s", curr) != EOF) {
        for (int i = 0; i < 3; i++) {
            int same = 0;
            for (int c = 7; c >= 0; c--) {
                if (curr[c] == special[i][c]) same++;
                else break;
            }
            if (same == 8) sum += 2000000;
        }
        for (int i = 0; i < 3; i++) {
            int same = 0;
            for (int c = 7; c >= 0; c--) {
                if (curr[c] == price[i][c]) same++;
                else break;
            }
            sum += p[same];
        }
    }
    printf("%d\n", sum);
    return 0;
}
