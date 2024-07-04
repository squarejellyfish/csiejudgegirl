#include <stdio.h>
#include <string.h>

int main() {
    char last[32], curr[32];
    int last_len, curr_len, front = 0, first = 1, right = 1;

    while (scanf("%s", curr) != EOF) {
        if (first) {
            printf("%s\n", curr);
            curr_len = strlen(curr);
            front += curr_len - 1;
            last_len = curr_len, first = 0;
            strcpy(last, curr), right = 0;
            continue;
        }

        curr_len = strlen(curr);
        if (right) {
            if (curr[0] == last[last_len - 1]) {
                printf("%s\n", curr + 1);
            } else {
                printf("\n");
                for (int j = 0; j < front; j++) printf("*");
                printf("%s\n", curr);
            }
            front += curr_len - 1;
            right = !right;
        } else {
            if (curr[0] == last[last_len - 1]) {
                for (int i = 1; i < curr_len; i++)  {
                    for (int j = 0; j < front; j++) printf("*");
                    printf("%c", curr[i]);
                    if (i != curr_len - 1) printf("\n");
                }
            } else {
                for (int i = 0; i < curr_len; i++)  {
                    for (int j = 0; j < front; j++) printf("*");
                    printf("%c", curr[i]);
                    if (i != curr_len - 1) printf("\n");
                }
            }
            right = !right;
        }
        last_len = curr_len;
        strcpy(last, curr);
    }

    return 0;
}
