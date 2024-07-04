#include <stdio.h>

#define max(a, b) ((a) > (b) ? (a) : (b))

int field[100000];

int main() {
    int n;
    scanf("%d", &n);

    int idx, type;
    while (scanf("%d%d", &idx, &type) != EOF) {
        if (type == 0) {
            int h = max(field[idx] - 1, max(field[idx + 1], field[idx + 2]));
            field[idx] = field[idx + 1] = h + 2;
            field[idx + 2] = h + 1;
        } else if (type == 1) {
            int h = max(field[idx + 2] - 1, max(field[idx], field[idx + 1]));
            field[idx + 1] = field[idx + 2] = h + 2;
            field[idx] = h + 1;
        } else if (type == 2) {
            int h = max(field[idx], max(field[idx + 1], field[idx + 2]));
            field[idx] = field[idx + 2] = h + 1;
            field[idx + 1] = h + 2;
        } else if (type == 3) {
            int h = max(field[idx] - 1, max(field[idx + 1], field[idx + 2] - 1));
            field[idx] = field[idx + 2] = field[idx + 1] = h + 2;
        }
    }
    for (int i = 0; i < n; i++) 
        printf("%d%c", field[i], " \n"[i==n-1]);
}
