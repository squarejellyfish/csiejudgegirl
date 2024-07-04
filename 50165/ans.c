#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef struct{
    double a, b, c;
} s_line;

typedef struct{
    double x, y;
} s_pt;

int n;
s_line line[250];
s_pt pt[250];

void find_inter(s_line* s1, s_line *s2, s_pt* p){
    p->x = (s1->b * s2->c - s2->b * s1->c)  / (s1->a * s2->b - s2->a * s1->b);
    p->y = (s1->a * s2->c - s2->a * s1->c)  / (s2->a * s1->b - s1->a * s2->b);
}

double get_distance(s_pt* p1, s_pt* p2){
    return (double)sqrt((p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y));
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%lf %lf %lf", &line[i].a, &line[i].b, &line[i].c);
    }

    for(int i = 0; i < n - 1; i++){
        find_inter(&line[i], &line[i + 1], &pt[i]);
        printf("(%lf, %lf)\n", pt[i].x, pt[i].y);
    }
    find_inter(&line[n - 1], &line[0], &pt[n - 1]);
    printf("(%lf, %lf)\n", pt[n - 1].x, pt[n - 1].y);

    double ans = 0;
    for(int i = 0; i < n - 1; i++){
        ans += get_distance(&pt[i], &pt[i + 1]);
    }
    ans += get_distance(&pt[0], &pt[n - 1]);

    printf("%.3lf\n", ans);
}

