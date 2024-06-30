#include <stdio.h>
 
#define max(a, b) (a) > (b) ? (a) : (b)
 
int main() {
    int k;
    scanf("%d", &k);
 
    long long sum_cp = 0;
    int cp;
    int attr_count = 0, attr_each[3] = {0}, largest = -1, second_lar = -1;
    while (scanf("%d", &cp) != EOF) {
        // printf("curr cp = %d\n", cp);
        int attr = cp % 3;
        attr_each[attr]++;
        if (attr_each[attr] == k)
            attr_count++;
 
        if (cp >= largest) {
            second_lar = largest, largest = cp;
        }
        else if (cp > second_lar && cp < largest) second_lar = cp;

        if (attr_count == 3) { // team is formed
            // printf("sum += %d\n", second_lar);
            sum_cp += second_lar;
            attr_each[0] = 0, attr_each[1] = 0, attr_each[2] = 0;
            largest = -1, second_lar = -1;
            attr_count = 0;
        }
    }
    // if there is a team left
    if (second_lar != -1) {
        // printf("sum += %d\n", second_lar);
        sum_cp += second_lar;
    } else if (largest != -1) sum_cp += largest;
    printf("%lld\n", sum_cp);
 
    return 0;
}
