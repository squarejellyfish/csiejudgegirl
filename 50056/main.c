#include <stdio.h>
#include <string.h>

typedef struct {
    char name[64];
    int amount, price;
} Material;

int main() {
    int N, M;
    Material materials[128];
    scanf("%d %d", &N, &M);
    
    for (int n = 0; n < N; n++) {
        scanf(" %s %d %d", materials[n].name, &materials[n].amount, &materials[n].price);
    }

    char ans[64];
    int max_profit = 0;
    for (int m = 0; m < M; m++) {
        char product[64];
        int ing;
        scanf(" %s %d", product, &ing);
        int max_produce = 2147483647, cost = 0;
        for (int i = 0; i < ing; i++) {
            char mat[64];
            int amount;
            scanf(" %s %d", mat, &amount);

            // look for mat
            for (int n = 0; n < N; n++) {
                if (strcmp(materials[n].name, mat) == 0) {
                    cost += amount * materials[n].price;
                    if (materials[n].amount / amount < max_produce) {
                        max_produce = materials[n].amount / amount;
                    }
                }
            }
        }
        int selling;
        scanf("%d", &selling);
        if ((selling - cost) * max_produce > max_profit) {
            max_profit = (selling - cost) * max_produce;
            strcpy(ans, product);
        } else if ((selling - cost) * max_produce == max_profit && strcmp(product, ans) < 0) {
            max_profit = (selling - cost) * max_produce;
            strcpy(ans, product);
        }
    }
    printf("%s %d\n", ans, max_profit);

    return 0;
}
