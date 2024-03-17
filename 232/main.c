#include <stdio.h>


int main() {
    int year, first_day, n;
    int each[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    scanf("%d %d", &year, &first_day);
    if (year%400==0 || (year%4==0 && year%100!=0)) each[1]++;
    // for (int i = 0; i < 12; i++) printf("%d%c", accu[i], " \n"[i==11]);
    scanf("%d", &n);

    int month, day;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &month, &day);
        if (month < 1 || month > 12) {
            printf("-1\n");
        } else if (day < 1 || day > each[month-1]) {
            printf("-2\n");
        } else {
            for (int j = 0; j < month - 1; j++) day += each[j];
            day += first_day - 1;
            printf("%d\n", day % 7);
        }
    }

    return 0;
}
