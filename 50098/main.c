#include <stdio.h>

unsigned long long club[128];
int N, K;
int chosen[128];

int solve(int clubi, unsigned long long seen, int k) {
    if (k == K) {
        for (int i = 0; i < K; i++) {
            printf("%d\n", chosen[i]);
        }
        return 1;
    }
    if  (clubi >= N) return 0;

    unsigned long long overlap = club[clubi] & seen;
    if (!overlap) {
        chosen[k] = clubi;
        if (solve(clubi + 1, seen | club[clubi], k + 1)) return 1;
    }

    // do not choose this
    return solve(clubi + 1, seen, k);
}

int main() {
    scanf("%d %d", &N, &K);

    for (int i = 0; i < N; i++) {
        int M;
        scanf("%d", &M);
        for (int j = 0; j < M; j++) {
            int mi;
            unsigned long long idx = 1;
            scanf("%d", &mi);
            idx = idx << mi;
            club[i] |= idx; // set member in club[i]
        }
    }

    solve(0, 0ll, 0);

    return 0;
}
