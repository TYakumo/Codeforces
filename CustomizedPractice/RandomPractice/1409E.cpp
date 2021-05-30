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
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        int K;
        cin >> N >> K;
        UMI cnt;
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            ++cnt[x];
        }

        for (int i = 0; i < N; ++i) {
            int y;
            cin >> y;
        }

        auto iter = cnt.begin();
        VVLL acc;
        while (iter != cnt.end()) {
            acc.push_back({iter->first, iter->second});
            ++iter;
        }

        sort(acc.begin(), acc.end());
        for (int i = 1; i < acc.size(); ++i) {
            acc[i][1] += acc[i-1][1];
        }

        VLL best(acc.size());
        VI blimit(acc.size());
        VLL dp(acc.size());

        for (int i = 0; i < acc.size(); ++i) {
            int low = i;
            int up = acc.size()-1;
            int minus = i > 0 ? acc[i-1][1] : 0;
            blimit[i] = i;

            while (low <= up) {
                int mid = (low+up) / 2;

                if (acc[mid][0]-acc[i][0] <= K) {
                    low = mid+1;
                    blimit[i] = mid;
                    best[i] = acc[mid][1] - minus;
                } else {
                    up = mid-1;
                }
            }
        }

        dp.back() = best.back();
        for (int i = (int)acc.size()-2; i >= 0; --i) {
            dp[i] = max(dp[i+1], best[i]);
        }

        long long ans = 0;
        for (int i = 0; i < acc.size(); ++i) {
            int next = blimit[i]+1;
            long long sum = best[i];

            if (next < acc.size()) {
                sum += dp[next];
            }
            ans = max(ans, sum);
        }

        cout << ans << endl;
    }


    return 0;
}
