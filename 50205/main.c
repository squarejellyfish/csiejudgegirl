#include <stdio.h>
#include <string.h>

//                0123456789
char digit[11] = ")!@#$%^&*(";

int todigit(char c) {
    for (int i = 0; i < 10; i++) {
        if (digit[i] == c) return i;
    }
    return -1;
}

int main() {
    int ans = 0, stack = 0, curr = 0;
    char l = '+', c, str[1000001];
    scanf("%s", str);
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        c = str[i];
        if (c == '+') {
            if (l == '+') stack += curr;
            else if (l == '*') stack *= curr;
            ans += stack, curr = 0;
            stack = 0;
            l = c;
        } else if (c == '*') {
            if (l == '+') stack += curr;
            else if (l == '*') {
                if (stack == 0) stack = curr;
                else stack *= curr;
            }
            curr = 0;
            l = c;
        } else {
            int digit = todigit(c);
            // printf("digit = %d\n", digit);
            curr = curr * 10 + digit;
        }
    }
    if (l == '+') stack += curr;
    else if (l == '*') stack *= curr;
    ans += stack;

    printf("%d\n", ans);

    return 0;
}
