#include <stdio.h>
#include <string.h>

int table[1024] = {0};
char buckets[1024][10000][128];
int S, N, Q;

int hash(char word[128], int len) {
    int ret = 0;
    for (int i = 0; i < len; i++) {
        if (word[i] >= '0' && word[i] <= '9') ret += word[i] - '0';
        else ret += word[i];
    }
    return ret % S;
}

int main() {
    scanf("%d %d %d", &S, &N, &Q);

    int h;
    char word[128];
    for (int n = 0; n < N; n++) {
        scanf(" %s", word);
        h = hash(word, strlen(word));
        strcpy(buckets[h][table[h]++], word);
    }

    for (int q = 0; q < Q; q++) {
        scanf(" %s", word);
        h = hash(word, strlen(word));
        int found = 0;
        for (int i = 0; i < table[h]; i++) {
            if (strcmp(word, buckets[h][i]) == 0) {
                printf("%d\n", h);  
                found = 1;
                break;
            }
        }
        if (!found) printf("-1\n");
    }

    return 0;
}
