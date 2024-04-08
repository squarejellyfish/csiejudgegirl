#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int last = -1, pos = 0, curr;
    unsigned int num, start;
    for (int i = 0; i < N; i++) {
        start = 1 << 31;
        scanf("%d", &num);

        while (start != 0) {
//            printf("start: %d\n", start);
            curr = (num & start) > 0;
            if (curr != last && last != -1) {
                printf("\n");
                for (int _ = 0; _ < pos % 40; _++) printf(" ");
            }
            printf("%d", curr);
            start = start >> 1;
            pos++;
            last = curr;
        }
    }
    printf("\n");

    return 0;
}
