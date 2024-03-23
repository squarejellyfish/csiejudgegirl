#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int N, Q;
    char dic[80000][101];
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %s", dic[i]);
    }
    scanf(" %d", &Q);
    for (int q = 0; q < Q; q++) {
        char curr[101];
        scanf(" %s", curr);
        int curr_len = strlen(curr), printed = 0, cand_count = 0, cands[40000] = {0};
        for (int i = 0; i < N; i++) { // dic loop
            int len = strlen(dic[i]);
            if (len == curr_len) {
                int diff = 0;
                for (int j = 0; j < len && diff < 2; j++) {
                    if (dic[i][j] != curr[j]) diff++;
                }
                if (diff > 1) continue;
                if (diff == 0) {
                    printf(">%s", dic[i]);
                    printed = 1;
                    break;
                } else if (diff == 1) {
                    cands[cand_count] = i;
                    cand_count++;
                }
            } else if (abs(len - curr_len) == 1) {
                int diff;
                if (len - curr_len < 0) {
                    diff = 0;
                    for (int j = 0; j < curr_len && diff < 2; j++) {
                        if (curr[j] != dic[i][j - diff]) diff++;
                    }
                    if (diff < 2) {
                        cands[cand_count] = i;
                        cand_count++;
                    }
                } else if (len - curr_len > 0) {
                    diff = 0;
                    for (int j = 0; j < len && diff < 2; j++) {
                        if (dic[i][j] != curr[j - diff]) diff++;
                    }
                    if (diff < 2) {
                        cands[cand_count] = i;
                        cand_count++;
                    }
                }
            }
        }
        if (!printed && cand_count == 0) printf("!%s", curr);
        else if (!printed && cand_count != 0) {
            for (int i = 0; i < cand_count; i++) {
                printf("%c%s", " ?"[i==0], dic[cands[i]]);
            }
        }
        printf("\n");
    }
    return 0;
}
