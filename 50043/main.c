#include <stdio.h>

int nums[6];
//int in_t[2048][2048] = {{0}};

long long cross(int a, int b, int c, int d) {
    return ((long long)a * d) - ((long long)b * c);
}

int in_triangle(int x, int y) {
    int a = nums[0] - x, b = nums[1] - y;
    int c = nums[2] - x, d = nums[3] - y;
    int e = nums[4] - x, f = nums[5] - y;
    int p1 = cross(a, b, c, d), p2 = cross(c, d, e, f), p3 = cross(e, f, a, b);
    return ((p1 >= 0 && p2 >= 0 && p3 >= 0) || (p1 <=0 && p2 <= 0 && p3 <= 0));
}

int main() {
    for (int i = 0; i < 6; i++) scanf("%d", &nums[i]);
    int smallx = 2048, bigy = -2048, bigx = -2048, smally = 2048;
    for (int i = 0; i < 6; i++) {
        if (i % 2 == 0) {
            if (nums[i] < smallx) smallx = nums[i];
            if (nums[i] > bigx) bigx = nums[i];
        } else {
            if (nums[i] < smally) smally = nums[i];
            if (nums[i] > bigy) bigy = nums[i];
        }
    }
//    printf("%d, %d to %d, %d\n", smallx, smally, bigx, bigy);

    int blocks = 0;
    for (int x = smallx; x < bigx; x++) {
        for (int y = smally; y < bigy; y++) {
            if (in_triangle(x, y) && in_triangle(x + 1, y) && in_triangle(x, y + 1) && in_triangle(x + 1, y + 1)) {
//                printf("block of (%d, %d) in triangle\n", x, y);
                blocks++;
            }
        }
    }
    printf("%d\n", blocks);

    return 0;
}
