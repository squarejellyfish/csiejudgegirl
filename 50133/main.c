#include <stdio.h>
#include <string.h>

int cmp(char *a, char *b) {
    if (a[0] != b[0]) return a[0] - b[0];
    if (a[1] != b[1]) return a[1] - b[1];
    return a[2] - b[2];
}

void merge(char *a, char *b, char *c) {
    int a_count = strlen(a) / 3, b_count = strlen(b) / 3;
    int i = 0, j = 0, k = 0;

    while (i < a_count && j < b_count) {
//        printf("i = %d, j = %d, a_count = %d, b_count = %d\n", i, j, a_count, b_count);
        if (cmp(a + (i * 3), b + (j * 3)) < 0) { // a is smaller
            if (i == a_count - 1) {
                memcpy(c + (k * 3), a + (i * 3), 3);
                memcpy(c + ((k + 1) * 3), b + (j * 3), b_count * 3 - j);
                break;
            }
            memcpy(c + (k * 3), a + (i * 3), 3);
 //           printf("moved a[%d] to c[%d]\n", i, k);
            k++, i++;
        } else { // b is smaller
            if (j == b_count - 1) {
                memcpy(c + (k * 3), b + (j * 3), 3);
                memcpy(c + ((k + 1) * 3), a + i * 3, a_count * 3 - i);
                break;
            }
            memcpy(c + (k * 3), b + (j * 3), 3);
  //          printf("moved b[%d] to c[%d]\n", j, k);
            k++, j++;
        }
    }
}

int main() {
    char a[100000], b[100000], c[100000];

    scanf(" %s", a);
    int alt = 0;
    while (scanf(" %s", b) != EOF) {
        if (!alt) {
            // printf("merging a = %s and b = %s to c\n", a, b);
            merge(a, b, c);
            printf("%s\n", c);
            alt = !alt;
        } else {
            // printf("merging c = %s and b = %s to c\n", c, b);
            merge(c, b, a);
            printf("%s\n", a);
            alt = !alt;
        }
    }

    return 0;
}
