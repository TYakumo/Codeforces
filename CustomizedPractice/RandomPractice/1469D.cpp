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
#include <cassert>
#include <limits>
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;
using VLL = vector <long long>;

void solve(VVI& ans, int N) {
    if (N <= 2) {
        return ;
    } else {
        int sq = ceil(sqrt(N));

        for (int i = N-1; i > sq; --i) {
            ans.push_back({i, N});
        }

        ans.push_back({N, sq});
        ans.push_back({N, sq});

        solve(ans, sq);
    }
}

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        VVI ans;
        cin >> N;
        solve(ans, N);

        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
    }

    return 0;
}