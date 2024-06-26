#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    char name[64];
    int height;
    int weight;
    double BMI;
} Student;

Student studs[100001];

int cmp(const void *p1, const void* p2) {
    Student a = *((Student*)p1);
    Student b = *((Student*)p2);
    if (a.BMI != b.BMI)
        if (a.BMI < b.BMI) return -1;
        else if (a.BMI > b.BMI) return 1;
        else return 0;
    if (a.weight != b.weight)
        return a.weight - b.weight;
    if (a.height != b.height)
        return a.height - b.height;
    return strcmp(a.name, b.name);
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf(" %s %d %d", studs[i].name, &studs[i].height, &studs[i].weight);
        double d = (double)studs[i].height / (double)100;
        d *= d;
        studs[i].BMI = (double)studs[i].weight / d;
    }

    qsort(studs, N, sizeof(Student), cmp);
    for (int i = 0; i < N; i++) {
        Student curr = studs[i];
        printf("%s %d %d\n", curr.name, curr.height, curr.weight);
    }

    return 0;
}

