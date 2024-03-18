#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int val;
    int idx;
} Num;

typedef struct {
    int small;
    int big;
    int sum;
} Group;

int comp_num(const void *a, const void *b) {
    return (*(Num *)a).val - (*(Num *)b).val;
}
int comp_group(const void *a, const void *b) {
    Group m = *((Group *)a), n = *((Group *)b);
#ifdef INC
    if (m.sum != n.sum)
        return m.sum - n.sum;
    return m.small - n.small;
#endif
#ifdef DEC
    if (m.sum != n.sum)
        return n.sum - m.sum;
    return n.big - m.big;
#endif /* ifdef DEC */
}

Num nums[100000];
Group groups[100000];
void pairPrint(int numbers[], int n) {
    for (int i = 0; i < n; i++) {
        nums[i].val = numbers[i];
        nums[i].idx = i;
    }
    qsort(nums, n, sizeof(Num), comp_num);
    for (int i = 0; i < n / 2; i++) {
        groups[i].sum = nums[i].val + nums[n - i - 1].val;
        groups[i].small = nums[i].idx;
        groups[i].big = nums[n - i - 1].idx;

        if (groups[i].small > groups[i].big) {
            int tmp = groups[i].small;
            groups[i].small = groups[i].big;
            groups[i].big = tmp;
        }
    }
    qsort(groups, n / 2, sizeof(Group), comp_group);
#ifdef INC
    for (int i = 0; i < n / 2; i++) {
        printf("%d = numbers[%d] + numbers[%d]\n", groups[i].sum,
               groups[i].small, groups[i].big);
    }
#endif
#ifdef DEC
    for (int i = 0; i < n / 2; i++) {
        printf("%d = numbers[%d] + numbers[%d]\n", groups[i].sum, groups[i].big,
               groups[i].small);
    }
#endif
}
