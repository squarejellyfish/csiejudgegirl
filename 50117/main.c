#include <stdio.h>

int main() {
    int k;
    scanf("%d", &k);

    int digit, carry = 0, printed = 0, pos = 0;
    while (scanf(" %d", &digit) != EOF) {
        if (pos == 0) { // separate first one
            if (digit == 0) {
                printf("0\n");
                break;
            } else if (digit / k > 0) {
                printf("%d\n", digit / k);
                printed = 1;
            }
            carry = (digit % k) * 10;
            pos++;
            continue;
        }
        digit += carry;
        printf("%d\n", digit / k);
        printed = 1;
        carry = (digit % k) * 10;
    }
    if (carry && !printed) printf("0\n");

    return 0;
}
