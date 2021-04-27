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
using DI = deque <int>;

int main()
{
    int N;
    cin >> N;

    VLL val(N);
    for (int i = 0; i < N; ++i) {
        cin >> val[i];
    }

    sort(val.begin(), val.end());
    const long long INF = 1000000000LL * 1000000000LL;
    VVLL dKind;
    long long ans = INF;

    for (int i = 0; i < N;) {
        int ni = i;
        while (ni < N && val[ni] == val[i]) {
            ++ni;
        }
        dKind.push_back({val[i], ni-i});
        i = ni;
    }

    int K = dKind.size();
    VVLL dp(K, VLL(K, INF));

    for (int i = 0; i < K; ++i) {
        dp[i][i] = 0;
    }

    for (int len = 2; len <= K; ++len) {
        for (int i = 0; i+len-2 < K; ++i) {
            int j = i+len-2;

            if (dp[i][j] != INF) {
                // left
                if (i-1 >= 0) {
                    long long cost = dp[i][j] + (dKind[j][0] - dKind[i-1][0]) * dKind[i-1][1];
                    dp[i-1][j] = min(dp[i-1][j], cost);
                }

                // right
                if (j+1 < K) {
                    long long cost = dp[i][j] + (dKind[j+1][0] - dKind[i][0]) * dKind[j+1][1];
                    dp[i][j+1] = min(dp[i][j+1], cost);
                }
            }
        }
    }

    cout << dp[0][K-1] << endl;

    return 0;
}
