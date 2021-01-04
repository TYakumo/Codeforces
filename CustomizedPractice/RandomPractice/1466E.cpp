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
#include <queue>
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;
using VLL = vector <long long>;
using VVLL = vector <VLL>;

const long long MOD = 1000000000 + 7;

int main() {
    int TC;
    scanf("%d", &TC);

    while (TC--) {
        int N;
        scanf("%d", &N);

        const long long BITMAX = 61;
        VLL v(N);
        VLL cnt(BITMAX);
        long long tot = 0;

        for (int i = 0; i < N; ++i) {
            scanf("%lld", &v[i]);
            tot = (tot + v[i]) % MOD;
        }

        for (int i = 0; i < N; ++i) {
            long long tmp = v[i];
            while (tmp) {
                long long val = tmp & (-tmp);
                long long idx = __builtin_ctzll(val);
                ++cnt[idx];
                tmp -= val;
            }
        }

        VLL left(N);
        VLL right(N);

        for (int i = 0; i < N; ++i) {
            right[i] = (tot + v[i]%MOD*N)%MOD;

            long long tmp = v[i];

            while (tmp) {
                long long val = tmp & (-tmp);
                long long idx = __builtin_ctzll(val);
                long long mv = val%MOD;

                left[i] = (left[i] + mv*cnt[idx])%MOD;
                right[i] = (right[i] - mv*cnt[idx])%MOD;
                tmp -= val;
            }
        }

        long long ans = 0;

        for (int i = 0; i < N; ++i) {
            // cout << "DEBUG " << left[i] << " " << right[i] << endl;
            ans = (ans + left[i]*right[i]) % MOD;
        }
        printf("%lld\n", (ans + MOD) % MOD);
    }

    return 0;
}