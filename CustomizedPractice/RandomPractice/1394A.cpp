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
    int N;
    long long D;
    long long M;

    cin >> N >> D >> M;
    VVLL cand(2);

    for (int i = 0; i < N; ++i) {
        long long v;
        cin >> v;

        if (v > M) {
            cand[1].push_back(v);
        } else {
            cand[0].push_back(v);
        }
    }

    sort(cand[1].begin(), cand[1].end(), greater<long long>());
    sort(cand[0].begin(), cand[0].end());

    VVLL acc(2);

    for (int i = 0; i < 2; ++i) {
        long long res = 0;

        for (int j = 0; j < cand[i].size(); ++j) {
            res += cand[i][j];
            acc[i].push_back(res);
        }
    }

    long long ans = 0;
    for (int r = 0; r <= cand[1].size(); ++r) {
        long long remain = N-r;
        long long required = max(0LL, (r-1LL)*D);

        if (remain >= required) {
            VLL sval(2);
            if (r) {
                sval[1] = acc[1][r-1];
            }

            long long removed = required-((int)cand[1].size()-r);
            sval[0] = !acc[0].empty() ? acc[0].back() : 0;

            if (removed > 0) {
                sval[0] -= acc[0][removed-1];
            }

            ans = max(ans, sval[0] + sval[1]);
        }
    }

    cout << ans << endl;

    return 0;
}
