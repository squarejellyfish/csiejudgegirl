#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n, r, w, s;
    scanf("%d %d %d", &n, &r, &w);
    int ans[50][5] = {{0}};
    for (int i = 0; i < n; i++) {
        char a[6];
        scanf(" %s", a);
        int len = strlen(a);
        for (int c = 0; c < len; c++) {
            ans[i][a[c] - 'A']++;
        }
    }
    scanf("%d", &s);
    // for every students
    for (int i = 0; i < s; i++) {
        int score = 0;
        // for every question
        for (int a = 0; a < n; a++) {
            char this_ans[6];
            int table[5] = {0};
            scanf(" %s", this_ans);

            int len = strlen(this_ans), yes = 1;
            for (int c = 0; c < len; c++) {
                this_ans[c] = toupper(this_ans[c]);
                if (this_ans[c] - 'A' > 4) {
                    goto end;
                }

                table[this_ans[c] - 'A']++;
            }
            for (int t = 0; t < 5; t++) {
                if (ans[a][t] != table[t]) {
                    yes = 0;
                    score -= w;
                    break;
                }
            }
            if (yes) score += r;
            end: score += 0;
        }
        printf("%d\n", (score > 0) ? score : 0);
    }
    return 0;
}
