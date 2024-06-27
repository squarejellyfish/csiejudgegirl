#include <stdio.h>
#include <stdlib.h>

int main() {
    int digit, count = 0, odd = 0, even = 0, zero = 0, is_even = 0;
    while (scanf("%d", &digit) != EOF) {
        count++;
        if (digit % 2 == 0) is_even = 1;
        else is_even = 0;
        if (count % 2 == 0) even += digit;
        else odd += digit;
        if (!digit) zero++;
    }
    printf("%d\n", count);
    printf("%d\n", is_even);
    printf("%d\n", zero);
    printf("%d\n", (abs(odd - even) % 11 == 0) ? 1 : 0);

    return 0;
}
