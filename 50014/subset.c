#include "subset.h"

int *nums, N;

int dfs(int head, int K, int S) {
    if (S == 0) {
        if (K == 0) return 1;
        else return 0;
    }
    if (K <= 0) return 0;

    for (int i = head; i < N; i++) {
        if (dfs(i + 1, K - nums[i], S - 1)) {
            return 1;
        }
    }

    return 0;
}
 
int subset(int numbers[], int n, int K, int S){
    nums = numbers, N = n;
    return dfs(0, K, S);
}
