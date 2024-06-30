#include <stdio.h>
#include <limits.h>

#define max(a, b) (a) > (b) ? (a) : (b)
#define min(a, b) (a) > (b) ? (b) : (a)

int visited[1000000];

int maxi, mini; // max min value of each loop
int find(int *a, int *b[], int idx) {
    int loop_len = 0;
    maxi = INT_MIN, mini = INT_MAX;
    while (!visited[idx]) {
        visited[idx] = 1;
        loop_len++;
        maxi = max(a[idx], maxi);
        mini = min(a[idx], mini);
        idx = b[idx] - a;
    }
    return loop_len;
}

void loops(int N, int *A, int *B[], int ans[4]) {
    for (int i = 0; i < N; i++) visited[i] = 0;

    
    int ma = INT_MIN, mi = INT_MAX; // max min of max min loop
    int maxl = INT_MIN, minl = INT_MAX; // global max min loop len
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;

        // find loop
        int len = find(A, B, i);
        if (len > maxl) { // this the longest, we update ma no matter what
            maxl = max(maxl, len);
            ma = maxi;
        } else if (len == maxl) { // this the same as longest, we compare ma then update
            ma = max(maxi, ma);
        }
        if (len < minl) { // this the shortest, we update mi no matter what
            minl = min(minl, len);
            mi = mini;
        } else if (len == minl) { // shit is same as shortest, compare the update
            mi = min(mini, mi);
        }
    }
    ans[0] = maxl, ans[1] = minl, ans[2] = ma, ans[3] = mi;
}
