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

int solveHalf(const VI& B, const VI& P) {
    if (B.size() == 0 || P.size() == 0) {
        return 0;
    }

    VI idx(2);
    int ret = 0;
    int base = 0;
    VI matched(P.size());

    while (idx[0] < B.size() && idx[1] < P.size()) {
        if (B[idx[0]] == P[idx[1]]) {
            matched[idx[1]] = ++base;
            ++idx[0];
            ++idx[1];
        } else if (B[idx[0]] < P[idx[1]]) {
            ++idx[0];
        } else {
            matched[idx[1]] = base;
            ++idx[1];
        }
    }

    while (idx[1] < P.size()) {
        matched[idx[1]++] = base;
    }

    idx[0] = 0;
    for (int i = 0; i < P.size(); ++i) {
        while (idx[0] < B.size() && B[idx[0]] <= P[i]) {
            ++idx[0];
        }

        auto leftBound = lower_bound(P.begin(), P.end(), P[i]-idx[0]+1);
        int leftCnt = idx[0] == 0 ? (i+1) : leftBound-P.begin();
        int now = (i+1) - leftCnt;
        int beyond = base-matched[i];
        int tot = now + beyond;
        ret = max(ret, tot);
    }

    return ret;
}

int main() {
    int TC;

    cin >> TC;

    for (int tc = 0; tc < TC; ++tc) {
        int N;
        int M;

        cin >> N >> M;
        VI PB;
        VI PP;
        VI NB;
        VI NP;

        for (int i = 0; i < N; ++i) {
            int val;
            cin >> val;
            if (val < 0) {
                NB.push_back(-val);
            } else {
                PB.push_back(val);
            }
        }

        for (int i = 0; i < M; ++i) {
            int val;
            cin >> val;
            if (val < 0) {
                NP.push_back(-val);
            } else {
                PP.push_back(val);
            }
        }

        reverse(NB.begin(), NB.end());
        reverse(NP.begin(), NP.end());

        int left = solveHalf(NB, NP);
        int right = solveHalf(PB, PP);

        cout << left+right << endl;
    }

    return 0;
}