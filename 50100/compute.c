#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "compute.h"

typedef struct {
    char name[64];
    int paper_count;
    int cited_count;
} Table;

int cmp(const void* p1, const void* p2) {
    Table a = *((Table*)p1);
    Table b = *((Table*)p2);
    return strcmp(a.name, b.name);
}

void compute(paper P[], int N) {
    Table table[N];
    int count = 0;
    // compute paper count
    for (int i = 0; i < N; i++) {
        char *name = P[i].journalName;
        int found = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(table[j].name, name) == 0) {
                // printf("%s in table ++\n", name);
                table[j].paper_count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            // printf("%s not in table, adding\n", name);
            strcpy(table[count].name, name);
            table[count].paper_count = 1;
            table[count++].cited_count = 0;
        }
    }
    // compute cited count
    for (int i = 0; i < N; i++) {
        int num = P[i].numCitedPaper;
        for (int j = 0; j < num; j++) {
            int idx = P[i].citedPaperIndex[j];
            // look in table
            char *name = P[idx].journalName;
            for (int k = 0; k < count; k++) {
                if (strcmp(table[k].name, name) == 0) {
                    table[k].cited_count++;
                    break;
                }
            }
        }
    }
    // sort and print
    qsort(table, count, sizeof(Table), cmp);
    for (int i = 0; i < count; i++) {
        printf("%s %d/%d\n", table[i].name, table[i].cited_count, table[i].paper_count);
    }
}
