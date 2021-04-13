#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <iomanip>
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;
using VVVI = vector <VVI>;
using VLL = vector <long long>;
using VVLL = vector <VLL>;
using VVVLL = vector <VVLL>;
using UMI = unordered_map<int, int>;
using UMLL = unordered_map<long long, long long>;
using VS = vector <string>;
using VC = vector <char>;
const long long MOD = 1000000000 + 7;

long long solve(VVVLL& dp, int now, int k, int dir) {
    int B = dp.size()-1;

    if (now == 0 && dir == 1) {
        return 0;
    }

    if (now == B && dir == 0) {
        return 0;
    }

    if (dp[now][k][dir] != -1) {
        return dp[now][k][dir];
    }

    if (k <= 1) {
        return dp[now][k][dir] = 0;
    }

    int vdir = dir == 0 ? 1 : -1;
    dp[now][k][dir] = 0;
    long long ret = solve(dp, now + vdir, k, dir);
    ret += solve(dp, now, k-1, dir^1) + 1;
    ret %= MOD;

    return dp[now][k][dir] = ret;
}

int main()
{
    int TC;

    cin >> TC;

    for (int tc = 1; tc <= TC; tc++) {
        int N;
        int K;
        cin >> N >> K;

        VVVLL dp(N+1, VVLL(K+1, VLL(2, -1)));
        cout << solve(dp, 0, K, 0)+1 << endl;
    }

    return 0;
}
