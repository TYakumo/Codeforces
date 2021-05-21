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
using UMI = unordered_map<int, int>;
using UMLL = unordered_map<long long, long long>;
using DVI = deque <VI>;
using VDVI = vector <DVI>;

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        long long C;
        cin >> N >> C;

        VVLL A(N, VLL(2));
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < N-i; ++j) {
                cin >> A[j][i];
            }
        }

        long long ans = (C+A[0][0]-1)/A[0][0];
        VVLL DP(N, VLL(2));

        for (int i = 1; i < N; ++i) {
            long long upgradeNeed = max(0LL, A[i-1][1]-DP[i-1][1]);
            long long need = (upgradeNeed + A[i-1][0]-1)/A[i-1][0];
            DP[i][0] = DP[i-1][0]+need+1;
            DP[i][1] = DP[i-1][1]+need*A[i-1][0] - A[i-1][1];

            long long remain = max(0LL, C-DP[i][1]);
            long long res = DP[i][0] + (remain+A[i][0]-1) / A[i][0];
            ans = min(ans, res);
        }

        cout << ans << endl;
    }

    return 0;
}