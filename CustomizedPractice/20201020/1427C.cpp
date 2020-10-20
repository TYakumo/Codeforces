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
#include <deque>
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;

int main() {
    int R;
    int N;
    cin >> R >> N;

    VVI C(N+1, VI(3));
    C[0] = {0, 1, 1};

    for (int i = 1; i <= N; ++i) {
        cin >> C[i][0] >> C[i][1] >> C[i][2];
    }

    // sort(C.begin(), C.end());

    const int INF = 10000000;
    int ans = 0;
    VI dp(C.size()+1, -INF); // dp[i] is not 0, if it can't be treated as a start point
    dp[0] = 0;

    int preMax = -INF;
    int startIdx = 0;

    for (int i = 1; i <= N; ++i) {
        while (startIdx < i && C[i][0] - C[startIdx][0] >= 2*(R-1)) {
            preMax = max(preMax, 1+dp[startIdx++]);
        }

        dp[i] = max(dp[i], preMax);

        for (int j = max(0, i-2*R); j < i; ++j) {
            if (abs(C[j][1]-C[i][1]) + abs(C[j][2]-C[i][2]) <= C[i][0]-C[j][0]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }

        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}