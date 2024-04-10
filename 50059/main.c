#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char S[32];
    unsigned int N, pos = 0, start, num, val = 0;
    scanf(" %s %d", S, &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        start = 1 << 31;
        while (start != 0) {
            val += ((num & start) > 0) * pow(2, (4 - (pos % 5)));
            start = start >> 1;
            pos++;
            if (pos > 0 && pos % 5 == 0) {
                printf("%c", S[val]);
                val = 0;
            }
        }
    }
    printf("\n");

    return 0;
}
