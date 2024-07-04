#include <stdio.h>

int main() {
    int DPS[5000], healer[5000], tank[5000];
    int front = 0, rear = 0, h = 0, hfront = 0, t = 0, tfront = 0;
    int dpscount = 0, hcount = 0, tcount = 0;

    int id;
    while (scanf("%d", &id) != EOF) {
        int role = id % 3;
        if (role == 0) {
            DPS[rear % 5000] = id, rear++, dpscount++;
        } else if (role == 1) {
            healer[h % 5000] = id, h++, hcount++;
        } else {
            tank[t % 5000] = id, t++, tcount++;
        }
        if (dpscount >= 3 && hcount >= 1 && tcount >= 1) {
            for (int i = front; i < front + 3; i++) {
                printf("%d ", DPS[i % 5000]);
            }
            front += 3;
            printf("%d %d\n", healer[hfront % 5000], tank[tfront % 5000]);
            hfront++, tfront++;
            dpscount -= 3, hcount--, tcount--;
        }
    }

    return 0;
}
