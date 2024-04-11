#include <stdio.h>
 
int donation_val[64] = {0}, hate[64][64] = {0};
int cand[64], donation = 0, N;
 
void solve(int *curr_cand, int cand_n, int val) {
    if (cand_n == 0) {
        if (val > donation) donation = val;
        return;
    }
 
    int next[64], next_n = 0;
    for (int i = 1; i < cand_n; i++) {
        if (!hate[curr_cand[0]][curr_cand[i]]) next[next_n++] = curr_cand[i];
    }
 
    solve(next, next_n, val + donation_val[curr_cand[0]]);
    solve(curr_cand + 1, cand_n - 1, val);
}
 
int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &donation_val[i]);
        cand[i] = i;
    }
 
    for (int i = 0; i < N; i++) 
        for (int j = 0; j < N; j++) 
            scanf("%d", &hate[i][j]);
 
    solve(cand, N, 0);
    printf("%d\n", donation);
 
    return 0;
}
