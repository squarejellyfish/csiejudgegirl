#include "count_day.h"
#include <stdio.h>

void count_day(int year, int day, int month, int results[7]) {
    int D[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) D[1]++;
    int days = 0;
    for (int i = 0; i < month - 1; i++) days += D[i];
    int first_day = (day + (days % 7)) % 7;
    for (int i = first_day; i < first_day + D[month - 1]; i++) results[i % 7]++;
}
