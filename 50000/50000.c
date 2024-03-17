#include <stdio.h>
#include <stdlib.h>

long long k, neg_cnt = 0, pos_cnt = 0;
long long curr = 0, ans = 0;

long long max(long long a, long long b)
{
    if (a > b)
        return a;
    return b;
}

void update_neg()
{
    if (neg_cnt != 0) {
        if (neg_cnt == k) {
            if (curr > 0) curr++;
        } else {
            curr = 0;
        }
    }
    neg_cnt = 0;
}

void update_pos()
{
    if (pos_cnt != 0) {
        if (pos_cnt > k) curr = 1;
        else if (pos_cnt == k) curr++;
        else curr = 0;
    }
    ans = max(ans, curr);
    pos_cnt = 0;
}

int main()
{
    int num;
    scanf("%lld", &k);

    while (1)
    {
        scanf("%d", &num);
        if (num == 0)
            break;

        if (num > 0)
        {
            update_neg();
            pos_cnt++;
            // printf("curr = %lld, ans = %lld\n", curr, ans);
        }
        else
        {
            update_pos();
            neg_cnt++;
            // printf("curr = %lld, ans = %lld\n", curr, ans);
        }
    }
    update_pos();
    update_neg();

    if (ans == 1)
        ans = 0;
    printf("%lld\n", ans * k);

    return 0;
}
