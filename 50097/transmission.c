#include "transmission.h"
#include <string.h>

long long int buffer[1048576];
void transmission(long long int belt[],int N,int T) {
    int shift = (T / 64) % N, rest = T % 64;
    memcpy(buffer, belt, sizeof(long long) * shift);
    memmove(belt, belt + shift, sizeof(long long) * (N - shift));
    memcpy(belt + N - shift, buffer, sizeof(long long) * shift);

    for (int t = 0; t < rest; t++)  {
        int leftmost = (belt[0] < 0) ? 1 : 0;
        for (int i = 0; i < N; i++) {
            if (i != N - 1) {
                belt[i] = belt[i] << 1;
                if (belt[i + 1] < 0) belt[i]++;
            } else {
                belt[i] = belt[i] << 1;
                if (leftmost) belt[i]++;
            }
        }
    }
}
