#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;

int main() {
    int TC;
    cin >> TC;

    const int MAXV = 1000100;
    VI minp(MAXV, -1);
    VI dp(MAXV);

    for (int i = 2; i < MAXV; ++i) {
        if (minp[i] == -1) {
            for (int j = 2; i * j < MAXV; ++j) {
                if (minp[i*j] == -1) {
                    minp[i*j] = i;
                }
            }

            minp[i] = i;
        }
    }

    // 3 6 = > g = 3, 1, 2
    // 3 9 => g = 3, 1, 3
    // for a prime p
    // N <= np, gcd(a, b) = 1, val, p (not possible, cause if val < p, val+1 <= p)
    // N <= np, gcd(a, b) = p, a, b and a+b > p

    dp[1] = 1;
    const int INF = 100000000;

    for (int i = 2; i < MAXV; ++i) {
        ++dp[i];

        int div = minp[i];
        int maxmul = i / div; // maxmul + m > div => m >= div+1-maxmul
        long long target = div+1-maxmul;

        if (target > maxmul) {
            if (target*div < MAXV) {
                --dp[target*div]; // first number to make i not lonely
            }
        } else {
            --dp[i];
        }

        dp[i] += dp[i-1];
    }

    while (TC--) {
        int N;
        scanf("%d", &N);

        printf("%d\n", dp[N]);
    }

    return 0;
}