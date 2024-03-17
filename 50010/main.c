#include <stdio.h>
#include <string.h>

int main() {
    char word[111111];
    scanf("%s", word);
    char cmd[20];
    int len = strlen(word);
    while (1) {
        scanf(" %s", cmd);
        if (!strcmp(cmd, "end")) break;

        char a, b;
        if (!strcmp(cmd, "replace")) {
            scanf(" %c %c", &a, &b);
            for (int i = 0; i < len; i++) {
                if (word[i] == a) word[i] = b;
            }
        } else if (!strcmp(cmd, "remove")) {
            scanf(" %c", &a);
            int i = 0;
            while (word[i] != '\0' || i < len) {
                if (word[i] == a) {
                    for (int j = i; j < len; j++) {
                        word[j] = word[j+1];
                    }
                    len--;
                    continue;
                }
                i++;
            }
        } else if (!strcmp(cmd, "addhead")) {
            scanf(" %c", &a);
            for (int i = len + 1; i >= 1; i--) {
                word[i] = word[i-1];
            }
            word[0] = a;
            len++;
        } else if (!strcmp(cmd, "addtail")) {
            scanf(" %c", &a);
            word[len] = a;
            word[len+1] = '\0';
            len++;
        } else {
            printf("invalid command %s\n", cmd);
            return 0;
        }
    }
    printf("%s\n", word);
    return 0;
}
