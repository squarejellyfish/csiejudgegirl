#include <stdio.h>

int main() {
    int ans = 0;
    char c, last;
    while (scanf("%c", &c) != EOF) {
        if (c == '.') {
            scanf("%c", &c);
            if (c == '\0') {
                ans++;
                break;
            } else if (c == '\n') ans++;
            else if (c == ' ') {
                scanf("%c", &c);
                if (c == ' ') ans++;
            }
            last = c;
        }
    }
    if (last == '.') ans++;
    printf("%d\n", ans);
    return 0;
}
