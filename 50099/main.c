#include <stdio.h>
#include <stdint.h>

int seq[16384];
int balpoint[16384];

// 2 1 5 5
// sum = 13
// wei = 26
void balance(int start, int end) { // end is 1 over
    if (end - start < 3) return;

    int64_t sum = 0, weight = 0;
    for (int i = start; i < end; i++)  {
        sum += seq[i];
        weight += seq[i] * (i - start);
    }
    // if balpoint exist, means weight sum % sum == 0
    if (weight % sum != 0) return;
    int point = weight / sum + start;
    balpoint[point] = 1;

    balance(start, point);
    balance(point + 1, end);
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }

    balance(0, n);

    for (int i = 0; i < n; i++) {
        if (balpoint[i]) printf("%d\n", i);
    }

    return 0;
}
