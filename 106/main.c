#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char num[1024];
    while (1) {
        int two = 0, three = 0, five = 0, eleven = 0;
        scanf(" %s", num);
        if (strcmp(num, "-1") == 0) break;
        int len = strlen(num);
        if ((num[len - 1] - '0') % 2 == 0) two = 1;
        if ((num[len - 1] - '0') % 5 == 0) five = 1;
        int sum = 0, a = 0, b = 0;
        for (int i = 0; i < len; i++) {
            sum += num[i] - '0';
            if (i % 2 == 0) a += num[i] - '0';
            if (i % 2 == 1) b += num[i] - '0';
        }
        if (sum % 3 == 0) three = 1;
        if (abs(a - b) % 11 == 0) eleven = 1;
        printf("%s", (two == 1) ? "yes" : "no");
        printf(" %s", (three == 1) ? "yes" : "no");
        printf(" %s", (five == 1) ? "yes" : "no");
        printf(" %s\n", (eleven == 1) ? "yes" : "no");
    }
    return 0;
}
