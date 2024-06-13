#include <stdio.h>

int friend[32769][257];
int friends_count[32769] = {0};
int invited[32769] = {0};

int main() {
    int N, E;
    scanf("%d %d", &N, &E);

    for (int i = 0; i < E; i++) {
        int vi, vj;
        scanf("%d %d", &vi, &vj);
        friend[vi][friends_count[vi]++] = vj;
        friend[vj][friends_count[vj]++] = vi;
    }

    int curr;
    while (scanf(" %d", &curr) != EOF) {
        invited[curr] = 1;
        for (int i = 0; i < friends_count[curr]; i++) {
            invited[friend[curr][i]] = 1;
        }
    }
    for (int i = 0; i < N; i++) {
        if (!invited[i]) printf("%d\n", i);
    }

    return 0;
}
