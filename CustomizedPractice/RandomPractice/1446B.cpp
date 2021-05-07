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


int main() {
    int N;
    int M;
    cin >> N >> M;
    string S1;
    string S2;
    cin >> S1 >> S2;

    VVI dp(N+1, VI(M+1, -2));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (S1[i] == S2[j]) {
                dp[i][j] += 4;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            ans = max(ans, dp[i][j]);
            if (i+1 < N && j+1 < M) {
                int plus = S1[i+1] == S2[j+1] ? 2 : -2;
                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+plus);
            }

            dp[i+1][j] = max(dp[i+1][j], dp[i][j]-1);
            dp[i][j+1] = max(dp[i][j+1], dp[i][j]-1);
        }
    }

    cout << ans << endl;

    return 0;
}