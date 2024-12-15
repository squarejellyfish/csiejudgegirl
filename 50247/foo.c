#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buildTree.h"

void foo(char* expr) {
    expr = strtok(expr, " ");
    printf("%s\n", expr);
}

int main(void) {
    char expr[] = "! ( ( ( ! M && ( H && D ) ) && R ) || ! ! K )";

    buildTree(expr);
}
