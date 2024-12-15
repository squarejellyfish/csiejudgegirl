#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

typedef struct {
    char name[12];
    int wealth;
} Record;

int cmp(const void* p1, const void* p2) {
    Record *a = (Record*)p1, *b = (Record*)p2;
    if (a->wealth != b->wealth) return a->wealth - b->wealth;
    else return strcmp(a->name, b->name);
}

int main(int argc, char **argv) {
    char *file_name = argv[1];
    FILE *file = fopen(file_name, "rb");

    int n = 0;
    Record recs[1024];

    Record tmp;
    while (fread(&tmp, sizeof(Record), 1, file)) {
        recs[n++] = tmp;
    }
    qsort(recs, n, sizeof(Record), cmp);

    int num = 1, i;
    for (i = 1; i < n; i++) {
        // printf("rec[i].wealth = %d, step = %d, next = %d\n", recs[i].wealth, step, next);
        if (recs[i - 1].wealth / 1000 == recs[i].wealth / 1000) num++;
        else {
            printf("%d\n", num);
            num = 1;
        }
    }
    printf("%d\n", num); // last group

    // for (int i = 0; i < n; i++) {
    //     printf("name = %s\n", recs[i].name);
    //     printf("\twealth = %d\n", recs[i].wealth);
    // }
    // printf("max = %d, min = %d, step = %d\n", max, min, step);
    printf("%s\n", recs[0].name);
    int max = recs[n - 1].wealth;
    for (i = n - 1; i >= 0; i--) if (recs[i].wealth != max) break;
    printf("%s\n", recs[i + 1].name);
    if (n % 2 == 1) printf("%d\n", recs[n / 2].wealth);
    else {
        long long ans = ((long long)recs[n / 2].wealth + (long long)recs[n / 2 - 1].wealth);
        int avg = ans / 2;
        printf("%d\n", avg); 
    }
}
