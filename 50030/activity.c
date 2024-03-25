#include "activity.h"
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *p1, const void *p2) {
    return (*(Activity*)p1).end - (*(Activity*)p2).end;
}

int select(Activity activities[], int n) {
    qsort(activities, n, sizeof(Activity), cmp);
    int ret = 0, last = 0;
    for (int i = 0; i < n; i++) {
        if (activities[i].start < last) continue;
#ifdef PRINT
        printf("%d %d\n", activities[i].start, activities[i].end);
#endif
        last = activities[i].end;
        ret++;
    }
    return ret;
}
