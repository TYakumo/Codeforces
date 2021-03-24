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

int main() {
    int N;
    cin >> N;

    VI P(N);

    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }

    VI lx(N, 1);
    VI rx(N, 1);

    for (int i = N-2; i >= 0; --i) {
        if (P[i] > P[i+1]) {
            rx[i] = rx[i+1]+1;
        }
    }

    for (int i = 1; i < N; ++i) {
        if (P[i-1] < P[i]) {
            lx[i] = lx[i-1]+1;
        }
    }

    int maxLen = 0;
    int maxIdx = 0;
    int maxCnt = 0;

    for (int i = 0; i < N; ++i) {
        if (lx[i] > maxLen) {
            maxLen = lx[i];
            maxIdx = i;
            maxCnt = 0;
        }

        if (rx[i] > maxLen) {
            maxLen = rx[i];
            maxIdx = i;
            maxCnt = 0;
        }

        if (lx[i] == maxLen) {
            ++maxCnt;
        }

        if (rx[i] == maxLen) {
            ++maxCnt;
        }
    }

    int ans = 0;
    if (maxCnt == 1) {
        int targetLen = maxLen%2 == 1 ? maxLen-1 : maxLen;
        if (lx[maxIdx] == maxLen && rx[maxIdx] > targetLen) {
            ans = 1;
        } else if (rx[maxIdx] == maxLen && lx[maxIdx] > targetLen) {
            ans = 1;
        }
    } else if (maxCnt == 2) {
        if (lx[maxIdx] == rx[maxIdx] && maxLen%2 == 1) {
            ans = 1;
        }
    } else if (maxCnt >= 3) {
        ans = 0;
    }

    cout << ans << endl;

    return 0;
}