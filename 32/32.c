#include <stdio.h>

int a[128];

int isPalind(int h, int t) {
    if (h == t) return 1;
    int c = t - h - 1; // count of numbers in between
    for (int i = 1; i < c; i++) {
        if (t - i < h + i) break;
        if (a[h+i] != a[t-i]) return 0;
    }
    return 1;
}

int main() {
    int c = 0;
    while (scanf("%d", &a[c]) != EOF) c++;
    // if (c < 3) {
    //     for (int i = 0; i < c; i++) printf("%d%c", a[i], " \n"[i==c-1]);
    //     return 0;
    // }
    int heads[128], tails[128], count = 0;
    for (int i = 0; i < c; i++) {
        for (int j = c - 1; j >= i; j--) {
            if (a[i] == a[j] && isPalind(i, j)) {
                heads[count] = i;
                tails[count] = j;
                count++;
                break;
            }
        }
    }

    int max = 0, ansi = 0, ansj = 0;
    for (int i = 0; i < count - 1; i++) {
        int nexttail = tails[count - 1];
        for (int j = i + 1; j < count; j++) {
            if (heads[j] == tails[i] + 1) nexttail = tails[j];
        }
        int thishead = heads[i];
        if (nexttail == tails[i]) thishead = heads[i - 1];
        if (nexttail - thishead >= max) {
            max = nexttail - thishead;
            ansi = thishead;
            ansj = nexttail;
        }
    }

    // for (int i = 0; i < count; i++) {
    //     for (int j = head[i]; j <= tail[i]; j++) printf("%d", a[j]);
    //     printf("\n");
    // }

    for (int i = ansi; i <= ansj; i++) printf("%d%c", a[i], " \n"[i==ansj]);

    return 0;
}
