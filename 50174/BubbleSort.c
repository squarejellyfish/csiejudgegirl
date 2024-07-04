#include "BubbleSort.h"
#include <stdint.h>
#include <stdio.h>

void BubbleSort(uint64_t input, uint64_t output[63]) {
    for (int t = 0; t < 63; t++) {
        for (int i = 62; i >= 0; i--) {
            int left = (input >> (i + 1)) & 1, right = (input >> i) & 1;
            if (left && !right) {
                input |= ((uint64_t)1 << i);
                input ^= ((uint64_t)1 << (i + 1));
            }
        }
        output[t] = input;
    }
}
