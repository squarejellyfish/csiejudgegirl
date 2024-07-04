#include <stdio.h>

int main() {
    // value of largests and second largests
    int l1 = -1, s1 = -1, l2 = -1, s2 = -1, l3 = -1, s3 = -1;
    // position of largests and second largests
    int lar1[2] = {0}, sec1[2] = {0}, lar2[2] = {0}, sec2[2] = {0}, lar3[2] = {0}, sec3[2] = {0};
    // position of last seen 1 2 3
    int last1 = -1, last2 = -1, last3 = -1;
    // current number of nums in between each
    int b1 = 0, b2 = 0, b3 = 0;

    int num, idx = 0;
    while (scanf("%d", &num) != EOF) {
        if (num == 1) {
            if (last1 != -1) { // we've seen a one
                if (b1 >= l1) {
                    if (b1 == l1) { // if same, we only update
                        l1 = b1;
                        lar1[0] = last1, lar1[1] = idx;
                    } else {
                        s1 = l1, l1 = b1;
                        sec1[0] = lar1[0], sec1[1] = lar1[1];
                        lar1[0] = last1, lar1[1] = idx;
                    }
                } else if (b1 >= s1) {
                    s1 = b1;
                    sec1[0] = last1, sec1[1] = idx;
                }
            }
            b1 = 1; // reset
            last1 = idx;
        } else b1++; // num between increase
        if (num == 2) {
            if (last2 != -1) {
                if (b2 >= l2) {
                    if (b2 == l2) { // if same, we only update
                        l2 = b2;
                        lar2[0] = last2, lar2[1] = idx;
                    } else {
                        s2 = l2, l2 = b2;
                        sec2[0] = lar2[0], sec2[1] = lar2[1];
                        lar2[0] = last2, lar2[1] = idx;
                    }
                } else if (b2 >= s2) {
                    s2 = b2;
                    sec2[0] = last2, sec2[1] = idx;
                }
            }
            b2 = 1;
            last2 = idx;
        } else b2++;
        if (num == 3) {
            if (last3 != -1) {
                if (b3 >= l3) {
                    if (b3 == l3) { // if same, we only update
                        l3 = b3;
                        lar3[0] = last3, lar3[1] = idx;
                    } else {
                        s3 = l3, l3 = b3;
                        sec3[0] = lar3[0], sec3[1] = lar3[1];
                        lar3[0] = last3, lar3[1] = idx;
                    }
                } else if (b3 >= s3) {
                    s3 = b3;
                    sec3[0] = last3, sec3[1] = idx;
                }
            }
            b3 = 1;
            last3 = idx;
        } else b3++;
        idx++;
    }
    printf("%d %d %d\n", s1, sec1[0], sec1[1]);
    printf("%d %d %d\n", s2, sec2[0], sec2[1]);
    printf("%d %d %d\n", s3, sec3[0], sec3[1]);

    return 0;
}
