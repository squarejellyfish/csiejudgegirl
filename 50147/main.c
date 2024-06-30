#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define max(a, b) (a) > (b) ? (a) : (b)

typedef struct point {
    int x;
    int y;
    int rad;
} Point;

Point points[1000100];

int cmp(const void *p1, const void *p2) {
    return ((Point*)p1)->rad - ((Point*)p2)->rad;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
        points[i].rad = points[i].x * points[i].x + points[i].y * points[i].y;
    }
    qsort(points, N, sizeof(Point), cmp);

    int count = 0, max_count = INT_MIN, max_rad = INT_MIN, last_rad = -1;
    for (int i = 0; i < N; i++) {
        int rad = points[i].rad;
        if (rad > last_rad) { // encounter new rad, reset count
//            printf("last rad %d has %d points\n", last_rad, count);
            if (count >= max_count) {
//                printf("new max_count %d, max_rad = %d\n", count, rad);
                max_count = max(max_count, count);
                max_rad = last_rad;
            }
            count = 1;
        } else // same rad
            count++;
        last_rad = rad;
    }
    if (count >= max_count) {
        max_count = max(max_count, count);
        max_rad = points[N - 1].rad;
    }
    printf("%d\n", max_rad);

    return 0;
}
