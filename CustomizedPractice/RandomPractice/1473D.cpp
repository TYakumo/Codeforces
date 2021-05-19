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
        int M;
        string S;
        cin >> N >> M;
        cin >> S;

        const int INF = 100000000;
        VVI acc(2, VI(N+1));
        VVVI range(2, VVI(N+1, VI(2, 0)));

        for (int i = 1; i <= N; ++i) {
            int plus = S[i-1] == '+' ? 1 : -1;
            acc[0][i] = acc[0][i-1] + plus;
            range[0][i] = range[0][i-1];
            range[0][i][0] = min(range[0][i][0], acc[0][i]);
            range[0][i][1] = max(range[0][i][1], acc[0][i]);
        }

        for (int i = N-1; i >= 0; --i) {
            int plus = S[i] == '+' ? -1 : 1;
            acc[1][i] = acc[1][i+1] + plus;
            range[1][i] = range[1][i+1];
            range[1][i][0] = min(range[1][i][0], acc[1][i]);
            range[1][i][1] = max(range[1][i][1], acc[1][i]);
        }

        while (M--) {
            int L;
            int R;
            cin >> L >> R;

            VVI r(2, {INF, -INF});
            int finalVal = acc[0][N]-acc[0][R]+acc[0][L-1];
            r[0] = range[0][L-1];

            if (R < N) {
                r[1] = range[1][R+1];
                r[1][0] += finalVal;
                r[1][1] += finalVal;
            }

            int maxp = max(r[0][1], r[1][1]);
            int minp = min(r[0][0], r[1][0]);

            cout << maxp-minp+1 << endl;
        }
    }

    return 0;
}