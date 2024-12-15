#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char name[12];
    int w;
} s_acct;

int cmp(const void* a, const void* b){
    s_acct* acct_a = (s_acct*) a;
    s_acct* acct_b = (s_acct*) b;
    if(acct_a->w > acct_b->w) return 1;
    else if(acct_a->w < acct_b->w) return -1;
    else return strcmp(acct_a->name, acct_b->name);
}

int main(int args, char* argv[]){
    s_acct acct[1024];

    FILE* fp = fopen(argv[1], "rb");
    int n = 0;
    while(fread(&acct[n], 16, 1, fp) == 1){
        n++;
    }
    qsort(acct, n, sizeof(s_acct), cmp);
    // for(int i = 0; i < n; i++){
    //     printf("%s %d\n", acct[i].name, acct[i].w);
    // }
    // printf("%d\n", n);

    int cnt = 1;
    for(int i = 1; i < n; i++){
        if(acct[i - 1].w / 1000 != acct[i].w / 1000){
            printf("%d\n", cnt);
            cnt = 1;
        }
        else{
            cnt++;
        }
    }
    printf("%d\n", cnt);

    printf("%s\n", acct[0].name);
    int max_num = acct[n - 1].w;
    int max_idx;
    for(max_idx = n - 1; max_idx >= 0; max_idx--){
        if(acct[max_idx].w != max_num) break;
    }
    max_idx++;
    printf("%s\n", acct[max_idx].name);

    if(n % 2 == 1){
        printf("%d\n", acct[n / 2].w);
    }
    else{
        long long sum = (long long)acct[n / 2].w + (long long)acct[n / 2 - 1].w;
        int avg = sum / 2;
        printf("%d\n", avg);
    }
}

