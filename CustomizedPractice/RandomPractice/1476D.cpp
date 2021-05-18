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
        cin >> N;
        string adja;
        cin >> adja;

        VVVI dp(2, VVI(N+1, VI(2))); // toLeft, toRight
        for (int i = 0; i <= N; ++i) {
            dp[0][i][0] = dp[0][i][1] = dp[1][i][0] = dp[1][i][1] = i;
        }

        // toLeft
        for (int i = 1; i <= N; ++i) {
            if (adja[i-1] == 'L') {
                dp[0][i][0] = min(dp[0][i][0], dp[0][i-1][1]);
            }

            if (adja[i-1] == 'R') {
                dp[0][i][1] = min(dp[0][i][1], dp[0][i-1][0]);
            }
        }

        // toRight
        for (int i = N-1; i >= 0; --i) {
            if (adja[i] == 'R') {
                dp[1][i][0] = max(dp[1][i][0], dp[1][i+1][1]);
            }

            if (adja[i] == 'L') {
                dp[1][i][1] = max(dp[1][i][1], dp[1][i+1][0]);
            }
        }

        cout << dp[1][0][0] - dp[0][0][0] + 1;
        for (int i = 1; i <= N; ++i) {
            cout << " " << dp[1][i][0] - dp[0][i][0] + 1;
        }
        cout << endl;
    }

    return 0;
}