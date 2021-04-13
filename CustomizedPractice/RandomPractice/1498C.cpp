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

int main()
{
    int TC;

    cin >> TC;

    for (int tc = 1; tc <= TC; tc++) {
        int N;
        int K;
        cin >> N >> K;

        VVVLL dp(K+1, VVLL(N+1, VLL(2)));

        for (int k = 2; k <= K; ++k) {
            for (int j = N-1; j >= 0; --j) {
                dp[k][j][0] = (dp[k][j+1][0] + dp[k-1][j][1] + 1) % MOD;
            }

            for (int j = 1; j <= N; ++j) {
                dp[k][j][1] = (dp[k][j-1][1] + dp[k-1][j][0] + 1) % MOD;
            }
        }

        cout << dp[K][0][0]+1 << endl;
    }

    return 0;
}
