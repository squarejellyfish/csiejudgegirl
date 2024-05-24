#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "elevator.h"

int main() {
    int N;
    scanf("%d", &N);
    int u, d, F;
    char ins[2048];
    Elevator *elevator;
    int len;
    for (int n = 0; n < N; n++) {
        scanf("%d %d %d", &u, &d, &F);
        elevator = newElevator(u, d, F);

        scanf(" %s", ins);
        len = strlen(ins);
        int res;
        for (int i = 0; i < len; i++) {
            if (ins[i] == 'U') {
                res = up(elevator);
            } else if (ins[i] == 'D') {
                res = down(elevator);
            }
            if (res == 1) {
                printf("Valid %d\n", getPosition(elevator));
            } else if (res == 0) {
                printf("Invalid\n");
            } else if (res == -1) {
                printf("Broken\n");
                break;
            }
        }

        for (int i = 1; i <= F; i++) {
            if (visited(elevator, i)) printf("%d\n", i);
        }
        free(elevator);
    }
    return 0;
}
