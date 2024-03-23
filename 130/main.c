#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 128

int main() {
    int n;
    scanf("%d", &n);
    char s1[MAXN], s2[MAXN];
    for (int i = 0; i < n; i++) {
        scanf(" %s %s", s1, s2);
        int len1 = strlen(s1), len2 = strlen(s2);
        if (!strcmp(s1, s2)) {
            printf("yes\n");
            continue;
        } else if (abs(len1 - len2) == 1) {
            int sh = (len1 < len2) ? len1 : len2;
            if (sh == len2) {
                char temp[MAXN];
                strcpy(temp, s1);
                strcpy(s1, s2);
                strcpy(s2, temp);
            }
            int diff = 0;
            for (int i = 0; i < len1 && diff < 2; i++) {
                if (s1[i] == s2[i+diff]) continue;
                diff++;
                if (s1[i] == s2[i+diff]) continue;
                diff++;
            }
            printf("%s\n", (diff < 2) ? "yes" : "no");
        } else if (len1 == len2) {
            int fucked = 0, diff = 0;
            for (int i = 0; i < len1 && !fucked; i++) {
                if (s1[i] == s2[i]) continue;
                if (s1[i] == s2[i+1] && s1[i+1] == s2[i] && diff < 1) {
                    i++;
                    diff++;
                    continue;
                }
                fucked = 1;
            }
            printf("%s\n", (!fucked) ? "yes" : "no");
        } else printf("no\n");
    }
    return 0;
}
