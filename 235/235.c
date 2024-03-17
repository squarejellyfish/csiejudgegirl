#include <stdio.h>

#define M 20

typedef long long ll;

ll gcd(ll a, ll b) {
    ll temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

typedef struct {
    ll up, down;
} Frac;

Frac pins[M][M], dp[M][M];

int main() {
    int n;
    scanf("%d", &n);

    ll left, right;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            scanf("%lld %lld", &left, &right);
            right = left + right;
            ll g = gcd(left, right);
            left /= g, right /= g;
            pins[i][j].up = left, pins[i][j].down = right;
        }
    }

    for (int i = 0; i < M; i++) for (int j = 0; j < M; j++) {dp[i][j].up = 0, dp[i][j].down = 1;}
    dp[0][0].up = 1, dp[0][0].down = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            // mul
            ll lastup = dp[i][j].up, lastdown = dp[i][j].down;
            ll thisup = pins[i][j].up, thisdown = pins[i][j].down;
            thisup *= lastup, thisdown *= lastdown;
            ll g = gcd(thisup, thisdown);
            thisup /= g, thisdown /= g;
            // add
            ll a = dp[i+1][j].up * thisdown + dp[i+1][j].down * thisup, b = dp[i+1][j].down * thisdown;
            g = gcd(a, b);
            a /= g, b /= g;
            dp[i+1][j].up = a, dp[i+1][j].down = b;
            // mul
            thisup = pins[i][j].down - pins[i][j].up, thisdown = pins[i][j].down;
            thisup *= lastup, thisdown *= lastdown;
            g = gcd(thisup, thisdown);
            thisup /= g, thisdown /= g;
            // add
            a = dp[i+1][j+1].up * thisdown + dp[i+1][j+1].down * thisup, b = dp[i+1][j+1].down * thisdown;
            g = gcd(a, b);
            a /= g, b /= g;
            dp[i+1][j+1].up = a, dp[i+1][j+1].down = b;
        }
    }

    for (int i = 0; i <= n; i++) printf("%lld/%lld\n", dp[n][i].up, dp[n][i].down);



    return 0;
}
