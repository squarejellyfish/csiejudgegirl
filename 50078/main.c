#include <stdio.h>

int main() {
    int ax, ay, bx, by, cx, cy;
    scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);
    
    printf("%d\n", bx + (cx - ax));
    printf("%d\n", by + (cy - ay));
    printf("%d\n", ax + (cx - bx));
    printf("%d\n", ay + (cy - by));
    printf("%d\n", ax + (bx - cx));
    printf("%d\n", ay + (by - cy));

    return 0;
}
