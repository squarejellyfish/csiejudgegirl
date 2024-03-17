#include <stdio.h>

int main() {
    char a[3], b[64];
    int ans = 0;
    scanf(" %s %s", a, b);

    for (int i = 0; i < 6; i++) {
        if (b[i] == a[0] && b[i+1] == a[1]) ans++;
    }

    printf("%d\n", ans);

    return 0;
}
