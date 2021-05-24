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

        VVLL X(N, VLL(2));
        const long long INF = 1000000000LL*1000;
        for (int i = 0; i < N; ++i) {
            cin >> X[i][0] >> X[i][1];
        }

        X.push_back({INF, 0});
        VI passed(N+1);
        long long nowp = 0;
        long long nowt = X[0][0];
        long long dir = X[0][1] > 0 ? 1 : -1;
        long long stopt = X[0][0] + abs(X[0][1]);

        if (X[0][1] == 0) {
            dir = 0;
        }

        for (int i = 1; i < X.size(); ++i) {
            if (X[i][0] >= stopt) { // start new target
                long long endp = (stopt-nowt)*dir + nowp;
                long long maxp = max(nowp, endp);
                long long minp = min(nowp, endp);

                if (X[i-1][1] >= minp && X[i-1][1] <= maxp) {
                    passed[i-1] = 1;
                }

                nowp = endp;
                nowt = X[i][0];
                stopt = X[i][0] + abs(X[i][1] - nowp);
                dir = 0;

                if (X[i][1] > nowp) {
                    dir = 1;
                } else if (X[i][1] < nowp) {
                    dir = -1;
                }
            } else {
                long long tdiff = X[i][0] - nowt;
                long long nextp = nowp + dir * tdiff;

                long long maxp = max(nowp, nextp);
                long long minp = min(nowp, nextp);

                if (X[i-1][1] >= minp && X[i-1][1] <= maxp) {
                    passed[i-1] = 1;
                }

                nowt = X[i][0];
                nowp = nextp;
            }
        }

        int ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += passed[i];
        }

        cout << ans << endl;
    }

    return 0;
}