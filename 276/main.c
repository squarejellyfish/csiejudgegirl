#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXN 1024

int invalid(char* word) {
    if (strcmp(word, "of") == 0 || strcmp(word, "and") == 0 || strcmp(word, "the") == 0 || strcmp(word, "at") == 0 || strlen(word) == 0) return 1;
    return 0;
}

int main() {
    char word[MAXN], space;
    char ans[30][256];
    int a = 0, b = 0;
    while (scanf(" %[^.]", word) != EOF) {
        int len = strlen(word), last = -1;
        b = 0;
        for (int i = 0; i < len + 1; i++) {
            if (word[i] == ' ' || word[i] == '\n' || word[i] == '\0') {
                char sub[MAXN];
                strncpy(sub, word + last + 1, i - last);
                sub[i - last - 1] = '\0';
                if (!invalid(sub)) {
                    ans[a][b] = toupper(sub[0]);
                    b++;
                }
                last = i;
            }
        }
        ans[a][b] = '\0';
        a++;
        scanf("%c", &space);
    }
    for (int i = 0; i < a; i++) {
        printf("%s\n", ans[i]);
    }
    return 0;
}
