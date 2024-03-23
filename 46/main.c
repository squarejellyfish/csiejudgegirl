#include <stdio.h>
#include <string.h>

char string[2<<20];

int main() {
    char inst[10], arg[2][10];
    int n = 0;
    while (scanf(" %s", inst) != EOF) {
        if (!strcmp(inst, "insert")) {
            scanf(" %s %s", arg[0], arg[1]);
            if (!strcmp(arg[0], "left")) {
                for (int i = n + 1; i >= 1; i--) {
                    string[i] = string[i-1];
                }
                string[0] = arg[1][0];
            } else if (!strcmp(arg[0], "right")) {
                string[n+1] = '\0';
                string[n] = arg[1][0];
            } else {
                int pos;
                sscanf(arg[0], " %d", &pos);
                for (int i = n + 1; i >= pos; i--) {
                    string[i] = string[i-1];
                }
                string[pos-1] = arg[1][0];
            }
            n++;
        } else {
            scanf(" %s", arg[0]);
            if (!strcmp(arg[0], "left")) {
                for (int i = 0; i < n; i++) {
                    string[i] = string[i+1];
                }
            } else if (!strcmp(arg[0], "right")) {
                string[n-1] = '\0';
            } else {
                int pos;
                sscanf(arg[0], " %d", &pos);
                for (int i = pos - 1; i < n; i++) {
                    string[i] = string[i+1];
                }
            }
            n--;
        }
//        printf("%s\n", string);
    }
    int seq[100] = {0}, inseq = 0, count = 1;
    seq[string[0] - 'a'] = 1;
    for (int i = 1; i <= n; i++) {
        if (string[i] == string[i-1]) {
            inseq = 1, count++;
        } else {
            if (count > seq[string[i-1] - 'a']) {
                seq[string[i-1] - 'a'] = count;
            }
            inseq = 0, count = 1;
        }
    }
    int max = -1;
    for (int i = 0; i < 26; i++) {
        if (seq[i] > max) max = seq[i];
    }
    for (int i = 1; i <= n; i++) {
        if (string[i] == string[i-1]) {
            inseq = 1, count++;
        } else {
            if (count == max) {
                printf("%c ", string[i-1]);
            }
            inseq = 0, count = 1;
        }
    }
    printf("%d\n", max);
    return 0;
}
