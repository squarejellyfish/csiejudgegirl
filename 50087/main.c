#include <stdio.h>
#include <stdlib.h>

int nums[2049] = {0};

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) scanf("%d", &nums[i]);

    int iter = 0;
    while (iter <= n / 2) {
        // step 1
        for (int bal = 1; bal < n - 1; bal++) {
            int left = 0;
            for (int l = 0; l < bal; l++) {
                left += nums[l] * abs(l - bal);
            }
            int right = 0;
            for (int r = bal + 1; r < n; r++) {
                right += nums[r] * abs(r - bal);
            }
//            printf("left = %d, right = %d\n", left, right);
            if (left == right) {
                for (int i = 0; i < n; i++) {
                    if (i != 0) printf(" ");
                    if (i == bal) printf("v");
                    else printf("%d", nums[i]);
                }
                return 0;
            }
        }
        // step 2
        int foo = nums[iter];
        nums[iter] = nums[n - iter - 1];
        nums[n - iter - 1] = foo;
        iter++;
    }

    return 0;
}
