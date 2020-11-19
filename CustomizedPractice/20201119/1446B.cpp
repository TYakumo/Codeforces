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
#include <queue>
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;

int main() {
    int N;
    int M;
    string A;
    string B;

    cin >> N >> M;
    cin >> A >> B;

    VVI dp(N+1, VI(M+1));
    int ans = 0;

    for (int i = 1; i <= A.size(); ++i) {
        for (int j = 1; j <= B.size(); ++j) {
            dp[i][j] = max(0, max(dp[i-1][j]-1, dp[i][j-1]-1));

            if (A[i-1] == B[j-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+4-2);
            }

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}