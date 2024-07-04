#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double points[256][2], lines[256][3];

void calculate_inter(double *line1, double *line2, double *point) {
    double a1 = line1[0], b1 = line1[1], c1 = line1[2];
    double a2 = line2[0], b2 = line2[1], c2 = line2[2];
    point[1] = (c2 * a1 - c1 * a2) / (b1 * a2 - b2 * a1);
    point[0] = -(b2 * (point[1]) + c2) / a2;
}

double dist(double p1[2], double p2[2]) {
    double a = p1[0] - p2[0], b = p1[1] - p2[1];
    return sqrt(a * a + b * b);
}

int main() {
    int N;
    scanf("%d", &N);

    // a1a2 x + b1a2 y + c1a2 = 0
    // a2a1 x + b2a1 y + c2a1 = 0
    // (b1a2 - b2a1) y = c2a1 - c1a2
    // x = -(b2 * y + c2) / a2
    scanf("%lf %lf %lf", &lines[0][0], &lines[0][1], &lines[0][2]);
    scanf("%lf %lf %lf", &lines[1][0], &lines[1][1], &lines[1][2]);
    calculate_inter(lines[0], lines[1], points[0]);
    double sum = 0;
    for (int i = 2; i < N; i++) {
        scanf("%lf %lf %lf", &lines[i][0], &lines[i][1], &lines[i][2]);
        calculate_inter(lines[i], lines[i - 1], points[i - 1]);
    }
    calculate_inter(lines[N - 1], lines[0], points[N - 1]);

    for (int i = 1; i < N; i++) {
        sum += dist(points[i], points[i - 1]);
    }
    sum += dist(points[0], points[N - 1]);

    printf("%.3lf\n", sum);

    return 0;
}
