#include "placement.h"
#include <limits.h>
#include <stdio.h>

void place(int bucket[1024],int N,int ball[16384],int M,int method,int result[16384]) {
    if (method == 0) {
        for (int i = 0; i < M; i++) {
            int curr = ball[i], placed = 0;
            for (int j = 0; j < N; j++) {
                if (bucket[j] >= curr) {
                    result[i] = j;
                    bucket[j] -= curr;
                    placed = 1;
                    break;
                }
            }
            if (!placed) result[i] = -1;
        }
    } else if (method == 1) {
        for (int i = 0; i < M; i++) {
            int curr = ball[i], idx = -1, sm = INT_MAX;
            for (int j = 0; j < N; j++) {
                if (bucket[j] - curr >= 0 && bucket[j] - curr < sm) {
                    sm = bucket[j] - curr;
                    idx = j;
                }
            }
            result[i] = idx;
            if (idx != -1) bucket[idx] = sm;
        }
    } else if (method == 2) {
        for (int i = 0; i < M; i++) {
            int curr = ball[i], idx = -1, lg = INT_MIN;
            for (int j = 0; j < N; j++) {
                if (bucket[j] - curr >= 0 && bucket[j] - curr >= lg) {
                    lg = bucket[j] - curr;
                    idx = j;
                }
            }
            result[i] = idx;
            if (idx != -1) bucket[idx] = lg;
        }
    }
}
