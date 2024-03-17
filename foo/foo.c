#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n;
    scanf("%d", &n);
    int even[n], odd[n], e = 0, o = 0;
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        if (num % 2 == 0) {
            even[e] = num;
            e++;
        } else {
            odd[o] = num;
            o++;
        }
    } 
    for (int i = 0; i < o; i++) printf("%d%c", odd[i], " \n"[i==o-1]);
    for (int i = 0; i < e; i++) {
        (i == e - 1) ? printf("%d", even[i]) : printf("%d ", even[i]);
    }
    return 0;
}
