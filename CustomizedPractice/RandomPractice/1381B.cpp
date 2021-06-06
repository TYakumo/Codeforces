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
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        cin >> N;

        VI A(2*N);
        for (int i = 0; i < A.size(); ++i) {
            cin >> A[i];
        }

        VI maxVal(A.size());
        VVVI dp(A.size()+1, VVI(N+2, VI(2)));

        int maxV = A[0];
        for (int i = 0; i < A.size(); ++i) {
            maxV = max(maxV, A[i]);
            maxVal[i] = maxV;
        }

        dp[1][0][0] = 1;
        // dp[1][1][1] = 1;
        for (int i = 1; i < A.size(); ++i) {
            for (int j = 0; j <= N; ++j) {
                dp[i+1][j][0] |= dp[i][j][0];
                dp[i+1][j+1][1] |= dp[i][j][1];

                if (A[i] == maxVal[i]) {
                    dp[i+1][j][0] |= dp[i][j][1];
                    dp[i+1][j+1][1] |= dp[i][j][0];
                }
            }
        }

        cout << (dp[A.size()][N][0] || dp[A.size()][N][1] ? "YES" : "NO") << endl;
    }

    return 0;
}