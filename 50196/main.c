#include <stdio.h>

#define isdigit(a) ((a)>=0 && (a)<=7)
#define isplus(a) ((a) == 8)
#define ismul(a) ((a) == 9)

int main() {
    int ans = 0, stack = 0, curr = 0;
    int c, l = 8;

    while (scanf("%d", &c) != EOF) {
        if (c == 0) break;
        if (isdigit(c)) {
            curr = curr * 10 + c;
        } else { // is operator
            // printf("is a op, curr = %d\n", curr);
            if (isplus(c)) {
                if (isplus(l)) stack += curr;
                else if (ismul(l)) stack *= curr;
                ans += stack, stack = 0;
            } else if (ismul(c)) {
                if (isplus(l)) stack += curr;
                else if (ismul(l)) {
                    if (stack == 0) stack = curr;
                    else stack *= curr; 
                }
            }
            // printf("ans = %d, stack = %d\n", ans, stack);
            l = c, curr = 0;
        }
    }
    // printf("last curr = %d\n", curr);
    if (isplus(l)) stack += curr;
    else if (ismul(l)) stack *= curr;
    ans += stack, stack = 0;
    
    printf("%d\n", ans);

    return 0;
}
