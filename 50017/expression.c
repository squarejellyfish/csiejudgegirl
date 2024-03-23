#include "expression.h"
#include <limits.h>

#define ERR -2147483648

int isDigit(char a) {
    if (a >= 48 && a <= 57) return 1;
    return 0;
}

int expressionEval(char *string, int *length) {
    if (isDigit(string[0])) {
        (*length)++;
        return string[0] - '0';
    }

    if (string[0] == '-') {
        int ret = expressionEval(string + 1, length);
        if (ret == ERR) return ERR;
        else {
            // *length++ is wrong
            (*length)++;
            return ret * (-1);
        }
    }
    if (string[0] != '(') return ERR;

    int left, right, l = 0, l2 = 0, ret;
    char operation;
    left = expressionEval(string + 1, &l);
    if (left == ERR) return ERR;
    operation = string[1 + l];
    right = expressionEval(string + 2 + l, &l2);
    if (right == ERR) return ERR;
//    printf("%d %c %d\n", left, operation, right);
    if (operation == '+') ret = left + right;
    else if (operation == '-') ret = left - right;
    else if (operation == '*') ret = left * right;
    else if (operation == '/') {
        if (right == 0) return ERR;
        ret = left / right;
    } else return ERR;

    if (string[1 + l + 1 + l2] == ')') {
        *length = l + l2 + 3;
        return ret;
    } else return ERR;
}
 
int expression(char *string){
    int i = 0, ret = INT_MIN, length = 0;
    while (string[i] != '\0') {
        if (ret != INT_MIN) return ERR;
        ret = expressionEval(string + i, &length);
        if (ret == ERR) return ERR;
        i += length;
    }
    return ret;
}
