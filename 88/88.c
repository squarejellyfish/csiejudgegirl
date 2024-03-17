#include <stdio.h>

int main() {
    char first[5], second[5];
    int A = 0, B = 0;
    scanf("%s %s", first, second);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (i == j) {
                if (first[i] == second[j]) A++;
            } else {
                if (first[i] == second[j]) B++;
            }
        }
    }
    printf("%dA%dB\n", A, B);
    return 0;
}
