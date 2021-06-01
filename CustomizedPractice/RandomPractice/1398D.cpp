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

int solve(const VVI& L, VVVI& dp, VI remain) {
    int zeroCnt = (remain[0] == 0) + (remain[1] == 0) + (remain[2] == 0);
    if (zeroCnt >= 2) {
        return 0;
    }

    VI N = {(int)dp.size()-1, (int)dp[0].size()-1, (int)dp[0][0].size()-1};
    int &ret = dp[remain[0]][remain[1]][remain[2]];

    if (ret != -1) {
        return ret;
    }

    if (remain[0] && remain[1]) {
        int plus = L[0][N[0]-remain[0]] * L[1][N[1]-remain[1]];
        VI nremain = remain;
        --nremain[0];
        --nremain[1];

        ret = max(ret, solve(L, dp, nremain)+plus);
    }

    if (remain[0] && remain[2]) {
        int plus = L[0][N[0]-remain[0]] * L[2][N[2]-remain[2]];
        VI nremain = remain;
        --nremain[0];
        --nremain[2];

        ret = max(ret, solve(L, dp, nremain)+plus);
    }

    if (remain[1] && remain[2]) {
        int plus = L[1][N[1]-remain[1]] * L[2][N[2]-remain[2]];
        VI nremain = remain;
        --nremain[1];
        --nremain[2];

        ret = max(ret, solve(L, dp, nremain)+plus);
    }

    return ret;
}

int main()
{
    VI N(3);
    VVI L(3);

    for (int i = 0; i < 3; ++i) {
        cin >> N[i];
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < N[i]; ++j) {
            int v;
            cin >> v;
            L[i].push_back(v);
        }
        sort(L[i].begin(), L[i].end(), greater<int>());
    }

    VVVI dp(N[0]+1, VVI(N[1]+1, VI(N[2]+1, -1)));
    cout << solve(L, dp, N) << endl;


    return 0;
}
