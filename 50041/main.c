#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int ll, l;
    long long cost = 0;
    scanf("%d %d", &ll, &l);
    if (l - ll > 0) { // uphill
        cost += (l - ll) * 3;
    } else cost += (ll - l) * 2;

    int curr, trans;
    for (int i = 0; i < n - 2; i++) {
        scanf("%d", &curr);
        trans = l - ll;
        if (curr - l > 0) {
            if (trans > 0) cost += (curr - l) * 4;
            else cost += (curr - l) * 3;
        }
        else if (curr - l < 0) {
            if (trans > 0) cost += (l - curr) * 3;
            else cost += (l - curr) * 2;
        }
        ll = l;
        l = curr;
    }
    printf("%lld\n", cost);

    return 0;
}
