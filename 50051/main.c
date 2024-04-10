#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int getHyphen(char *str){ // get the position of the hyphen (2 or 3, else return -1)
    if (str[2] == '-') return 2;
    return str[3] == '-' ? 3 : -1;
}

int valid(char plate[8]) {
    char char_count[128] = {0}, last = 0;
    int has_digit = 0, sum_digit = 0, dash = 0, hyphen = getHyphen(plate);

    if (hyphen == -1) return 0;
    for (int i = 0; i < 7; i++) {
        if ((!isalnum(plate[i])) && i != hyphen) {
//            printf("%s invalid char found\n", plate);
            return 0;
        }

        if (isdigit(plate[i])) {
            has_digit = 1;
            sum_digit += plate[i] - '0';
        }

        if (plate[i] == '4' && last == '4') {
//            printf("%s consecutive 4 found\n", plate);
            return 0;
        }

        char_count[plate[i]]++;
        if (char_count[plate[i]] > 2) {
//            printf("%s more than 2 char found\n", plate);
            return 0;
        }
        last = plate[i];
    }

    if (!has_digit || sum_digit % 7 == 0) {
//        printf("%s no digit or divided by 7\n", plate);
        return 0;
    }
    return 1;
}
int cmp(const void *p1, const void *p2) {
    return strcmp((char*)p1, (char*)p2);
}

int main() {
    int N, c1 = 0, c2 = 0;
    scanf("%d", &N);

    char plate[8], ans1[32][8], ans2[32][8];
    for (int i = 0; i < N; i++) {
        scanf(" %s", plate);
        if (valid(plate)) {
//            printf("%s is valid\n", plate);
            if (plate[2] == '-') strcpy(ans1[c1++], plate);
            else strcpy(ans2[c2++], plate);
        }
    }
    qsort(ans1, c1, sizeof(char)*8, cmp);
    qsort(ans2, c2, sizeof(char)*8, cmp);
    for (int i = 0; i < c1; i++) printf("%s\n", ans1[i]);
    for (int i = 0; i < c2; i++) printf("%s\n", ans2[i]);

    return 0;
}
