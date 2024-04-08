#include <stdio.h>
#include <limits.h>
#include <string.h>

int N, cost = INT_MAX;
char words[32][64];
int costs[32] = {0}, count[26] = {0};

void find_subset(int idx, int curr_cost, int char_count) {
//    printf("%d %d %d\n", idx, curr_cost, char_count);
    if (char_count == 26 && curr_cost < cost) {
        cost = curr_cost;
        return;
    }
    if (curr_cost > cost) return;

    for (int i = idx; i < N; i++) {
        int cc = 0, len = strlen(words[i]);
        for (int j = 0; j < len; j++) {
            if (!count[words[i][j] - 'a']) {
                cc++;
            }
            count[words[i][j] - 'a']++;
        }
        find_subset(i + 1, curr_cost + costs[i], char_count + cc);
        for (int j = 0; j < len; j++) {
            count[words[i][j] - 'a']--;
        }
    }

    return;
}

int main() {
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf(" %s %d", words[i], &costs[i]);
    }

    find_subset(0, 0, 0);
    printf("%d\n", cost);

    return 0;
}
