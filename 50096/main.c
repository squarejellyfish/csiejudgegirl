#include <stdio.h>
#include <stdint.h>

int N, M, P;
uint64_t valid_codes[4];
unsigned char text[256];

// helper function
void print_bin(unsigned char n) {
    for (int i = 7; i >= 0; i--) printf("%d", (n >> i) & 1);
    printf("\n");
}

int main() {
    scanf("%d %d %d", &N, &M, &P);

    for (int i = 0; i < M; i++) scanf("%llu", &valid_codes[i]);
    for (int i = 0; i < P; i++) scanf("%hhu", &text[i]);

    for (int i = 0; i < P; i++) {
        unsigned char t = text[i];
        for (int j = 0; j < N; j++) {
            // 0  1  2 3 4 5 6 7 
            // 56 48 ...
            unsigned char curr = (unsigned char)((valid_codes[j / 8] >> ((7 - j % 8) * 8)) & (uint64_t)255);
            if (curr == t) printf("%hhu\n", t);
            else { // diff != 0
                int dist = 0;
                unsigned char diff = curr ^ t;
                for (int k = 0; k < 8 && dist < 2; k++) {
                    if ((diff & (1 << k)) != 0) dist++;
                }
                if (dist == 1) printf("%hhu\n", curr);
            }
        }
    }

    return 0;
}
