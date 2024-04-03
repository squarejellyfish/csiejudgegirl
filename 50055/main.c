#include <stdio.h>

int main() {
    int counters[1024] = {0};
    int n, m;
    scanf("%d %d", &n, &m);

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int ready, need;
        scanf("%d %d", &ready, &need);
        int mini = 0;
        for (int j = 0; j < n; j++) {
            if (counters[j] < counters[mini]) mini = j;
        }
        if (counters[mini] > ready) ans += counters[mini] - ready;
        else if (counters[mini] < ready) counters[mini] = ready;
        counters[mini] += need;
    }
    printf("%d\n", ans);

    return 0;
}
