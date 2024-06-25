#include <stdio.h>
#include "compute.h"
#define MAXP 1024
paper P[1024];
int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %s %d", P[i].journalName, &P[i].numCitedPaper);
        for (int j = 0; j < P[i].numCitedPaper; j++)
            scanf("%d", &P[i].citedPaperIndex[j]);
    }
    compute(P, N);
    return 0;
}
