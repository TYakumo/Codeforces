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

const long long MOD = 998244353;
using VLL = vector <long long>;

long long modPow(long long n, long long p) {
    if (p == 0) {
        return 1;
    }

    long long hf = modPow(n, p/2);
    long long ret = hf * hf % MOD;

    if (p % 2 == 1) {
        ret = (ret * n) % MOD;
    }

    return ret;
}

int main() {
    int N;
    cin >> N;

    // for length 1 in N=3 => abc, aab, baa => 10*9*9 x 3, 10*9, 10*9 = 2610
    // length 2 => aab, baa => 180

    // 10*9*9*10^remain, middle = 810
    // 2*10*9*10^remain, corner = 1800

    for (int n = 1; n < N; ++n) {
        // fixed the start pos of a segment
        long long comb = 2*10*9*modPow(10, N-n-1) % MOD; // corner

        if (N-n-2 >= 0) {
            long long remain = N-n-2;
            comb += 810 * modPow(10, N-n-2) % MOD * (remain+1) % MOD; // middle
            comb %= MOD;
        }

        cout << (comb + MOD)%MOD << " ";
    }

    cout << "10" << endl;

    return 0;
}