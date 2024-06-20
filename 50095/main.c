#include <stdio.h>
#include <string.h>

char **words[1024], *s[16384], string[10000000];
int line_count[1024];

int main() {
    int N;
    char _;
    scanf("%d", &N);

    int used = 0, ptr2 = 0;
    for (int n = 0; n < N; n++) {
        // first level
        words[n] = &s[ptr2];
        while (scanf(" %s%c", string + used, &_) == 2) {
            // second level
            s[ptr2++] = string + used;
            used += strlen(string + used) + 1;
            line_count[n]++;
            if (_ == '\n') break;
        }
    }

    int M;
    scanf("%d", &M);

    for (int m = 0; m < M; m++) {
        int l1, w1, l2, w2;
        scanf("%d %d %d %d", &l1, &w1, &l2, &w2);
        char *tmp;
        tmp = words[l1][w1];
        words[l1][w1] = words[l2][w2];
        words[l2][w2] = tmp;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < line_count[i]; j++) {
            if (!j) printf("%s", words[i][j]);
            else printf(" %s", words[i][j]);
        }
        puts("");
    }

    return 0;
}
