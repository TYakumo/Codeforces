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
using VLL = vector <long long>;

const long long MOD = 998244353;

struct GCDInfo {
    long long x;
    long long y;
    long long g;
    GCDInfo(long long px, long long py, long long pg) : x(px), y(py), g(pg) {
    }
};

GCDInfo gcd(long long a, long long b) {
    if (b == 0) {
        return GCDInfo(1, 0, a);
    }

    // ax+by = g
    // bx'+(a-a/b*b)y' = g
    GCDInfo v = gcd(b, a%b);
    return GCDInfo(v.y, v.x-(a/b)*v.y, v.g);
}

// Get a * x mod p = 1
long long findInv(long long a, long long p) {
    return gcd(a, p).x;
}

int main() {
    int N;
    int K;

    scanf("%d%d", &N, &K);

    set <int> coor;
    unordered_map <int, long long> inc;
    unordered_map <int, long long> dec;
    int UPPER = N+10;
    VLL fact(UPPER);
    fact[0] = 1;

    for (int n = 1; n < UPPER; ++n) {
        fact[n] = fact[n-1]*n % MOD;
    }


    for (int i = 0; i < N; ++i) {
        int l;
        int r;
        scanf("%d%d", &l, &r);

        ++inc[l];
        ++dec[r+1];
        coor.insert(l);
        coor.insert(r+1);
    }

    auto iter = coor.begin();
    long long tot = 0;

    auto getC = [&fact](long long a, long long b) {
        if (b > a) {
            return 0LL;
        }
        // return fact[a] / (fact[a-b] * fact[b]) ;
        return fact[a] * findInv(fact[a-b], MOD) % MOD * findInv(fact[b], MOD) % MOD;
    };

    long long ans = 0;

    while (iter != coor.end()) {
        long long cInc = inc[*iter];
        long long cDec = dec[*iter];
        long long oldTot = tot - cDec;

        tot += cInc - cDec;

        // C(tot K)
        if (cInc > 0) {
            // ans += C(tot K) - C(oldTot K) => at least one in cInc
            ans += getC(tot, K) - getC(oldTot, K);
            ans %= MOD;
        }

        ++iter;
    }

    cout << (ans+MOD)%MOD << endl;



    return 0;
}