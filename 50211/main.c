#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// #define is_operator(a) (((a) == '+') || ((a) == '-') || ((a) == '*') || ((a) == '/'))
// #define isdigit(a) (((a)>='0') && ((a)<='9'))

typedef struct returnval {
    int valid;
    int value;
    int next; // what is this? 
} Info;

Info FAIL = (Info) {0, 0, 0};

char str[1000000];
int n;

int is_operator(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}
Info eval_num(int start) {
    int ret = 0;
    while (isdigit(str[start]) && start < n) {
        ret = ret * 10 + (str[start] - '0');
        start++;
    }
    return (Info) {1, ret, start};
}

Info expression(int start) {
    if (str[start] != '(') {
        return FAIL;
    }

    Info left, right;
    char op;
    start++;
    if (isdigit(str[start])) { // case 1: number operator number
        left = eval_num(start);
        op = str[left.next];
        if (!isdigit(str[left.next + 1])) return FAIL;
        right = eval_num(left.next + 1);
    } else if (str[start] == '(') { // case 2: expression operator expression
        left = expression(start);
        op = str[left.next];
        if (str[left.next + 1] != '(') return FAIL;
        right = expression(left.next + 1);
    }

    if (!left.valid || !right.valid || !is_operator(op) || str[right.next] != ')') return FAIL;

    if (op == '+') return  (Info) {1, left.value + right.value, right.next + 1};
    else if (op == '-') return  (Info) {1, left.value - right.value, right.next + 1};
    else if (op == '*') return  (Info) {1, left.value * right.value, right.next + 1};
    else if (op == '/') return  (Info) {1, left.value / right.value, right.next + 1};
}

int main() {

    while (scanf(" %s", str) != EOF) {
        n = strlen(str);
        Info res = expression(0);
        if (res.valid && res.next == n) printf("%d\n", res.value);
        else printf("invalid\n");
    }

    return 0;
}
