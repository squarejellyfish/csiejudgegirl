#include "splitAndMap.h"
#include <string.h>
#include <stdio.h>
#include <limits.h>

void splitAndMap(char*** ptr, char* str) {
    int n = 0, str_len = strlen(str);
    while (ptr[n]) n++;
    int p[n], l[n]; // pointer for Ai, length of Ai
    for (int i = 0; i < n; i++) p[i] = 0, l[i] = 0;
    
    char *curr = strtok(str, "*");
    while (curr != NULL) curr = strtok(NULL, "*");
    int i = 0;
    while (i < str_len) {
        if (str[i] == '*') {
            i++;
            continue;
        }
        curr = str + i;
//        printf("i = %d, curr = %s\n",i,  curr);
        int idx = 0, smallest = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (l[i] < smallest) {
                idx = i, smallest = l[i];
            }
        }
//        printf("putting in A%d\n", idx);
        ptr[idx][p[idx]] = curr;
        p[idx]++, l[idx] += strlen(curr);
//        printf("length is now %d\n", l[idx]);

        i += strlen(curr) + 1;
    }
    for (int i = 0; i < n; i++) ptr[i][p[i]] = NULL;
}
