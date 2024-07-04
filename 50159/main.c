#include <stdio.h>
#include <limits.h>

int main() {
    int inc = 0, dec = 0; // current up & down hill length
    int valley = 0, mountain = 0; // in valley or mountain or not (pass v or ^ or not)
    int piv1 = 1, piv2 = 1; // pivot point (v or ^)
    int longest = INT_MIN, left = INT_MIN, index = 0;

    int curr, last, i = 1;
    while (scanf("%d", &curr) != EOF) {
        if (i == 1) { // first one
            last = curr, i++;
            continue;
        }
        
        if (curr - last > 0) {
            if (mountain) { // we have seen a ^
                int mlen = inc + dec - 1;
                if (mlen > longest) {
                    longest = mlen, left = inc, index = piv1;
                } else if (mlen == longest && inc > left) {
                    left = inc, index = piv1;
                }
                // we now in valley
                inc = 2, valley = 1, mountain = 0, piv1 = piv2, piv2 = i - 1;
            } else if (valley) { // we have seen a v
                inc++;
            } else { // we only have seen / or down
                if (dec && !inc) {
                    valley = 1, piv2 = i - 1, inc = 2;
                } else if (!inc) inc = 2;
                else inc++;
            }
        } else {
            if (valley) { // we have seen a v
                int vlen = dec + inc - 1;
                if (vlen > longest) {
                    longest = vlen, left = dec, index = piv1;
                } else if (vlen == longest && dec > left) {
                    left = dec, index = piv1;
                }
                // we now in mountain
                dec = 2, valley = 0, mountain = 1, piv1 = piv2, piv2 = i - 1;
            } else if (mountain) { // we have seen a ^
                dec++;
            } else { // we only have seen / or down
                if (inc && !dec) {
                    mountain = 1, piv2 = i - 1, dec = 2;
                } else if (!dec) dec = 2;
                else 
                    dec++;
            }
        }
#ifdef DEBUG
        printf("i = %d\ninc = %d, dec = %d, valley = %d, mountain = %d, piv1 = %d, piv2 = %d, longest = %d, left = %d, index = %d\n", i, inc, dec, valley, mountain, piv1, piv2, longest, left, index);
#endif
        last = curr;
        i++;
    }
    if (mountain) {
        int mlen = inc + dec - 1;
        if (mlen > longest) {
            longest = mlen, left = inc, index = piv1;
        } else if (mlen == longest && inc > left) {
            left = inc, index = piv1;
        }
    } else if (valley) {
        int vlen = dec + inc - 1;
        if (vlen > longest) {
            longest = vlen, left = dec, index = piv1;
        } else if (vlen == longest && dec > left) {
            left = dec, index = piv1;
        }
    }

    if (!index) printf("0\n");
    else printf("%d %d\n", longest, index);

    return  0;
}
