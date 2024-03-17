#include <stdio.h>
#include <stdlib.h>

int main() {
    int m,n,x1,y1,e1,n1,f1,x2,y2,e2,n2,f2;
    scanf("%d %d %d %d %d %d %d %d %d %d %d %d", &m,&n,&x1,&y1,&e1,&n1,&f1,&x2,&y2,&e2,&n2,&f2);
    int ee1 = e1, nn1 = n1, ee2 = e2, nn2 = n2, t = 1;

    while (f1 || f2) {
        if (f1) { // robot 1
            if (nn1) {
                y1++;
                nn1--;
            } else if (ee1) {
                x1++;
                ee1--;
            }
            if (!nn1 && !ee1) {
                nn1 = n1;
                ee1 = e1;
            }
            // trans
            if (x1 == m) x1 = 0;
            if (y1 == n) y1 = 0;
            f1--;
        }
        if (f2) { // robot 2
            if (ee2) {
                x2++;
                ee2--;
            } else if (nn2) {
                y2++;
                nn2--;
            }
            if (!nn2 && !ee2) {
                nn2 = n2;
                ee2 = e2;
            }
            // trans
            if (x2 == m) x2 = 0;
            if (y2 == n) y2 = 0;
            f2--;
        }
        if (x1 == x2 && y1 == y2) {
            printf("robots explode at time %d\n", t);
            return 0;
        }
        t++;
    }
    printf("robots will not explode\n");
         
    return 0;
}
