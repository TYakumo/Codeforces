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
const int INF = 1000000010;

inline int checkMax(const VI& A, int pos) {
    if (pos == 0 || pos == A.size()-1) {
        return INF;
    }
    int theMax = max(A[pos-1], A[pos+1]);
    return theMax;
}

inline int checkMin(const VI& A, int pos) {
    if (pos == 0 || pos == A.size()-1) {
        return -INF;
    }
    int theMin = min(A[pos-1], A[pos+1]);
    return theMin;
}

inline int checkPlus(const VI& A, int pos) {
    if (A[pos] > checkMax(A, pos)) {
        return 1;
    }

    if (A[pos] < checkMin(A, pos)) {
        return 1;
    }

    return 0;
}

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        cin >> N;

        VI A(N);
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        for (int i = 0; i < N; ++i) {
            cnt += checkPlus(A, i);
        }

        int ans = cnt;

        for (int i = 0; i < N; ++i) {
            int tmp = A[i];
            VI cand;
            if (i+1 < N) {
                cand.push_back(A[i+1]);
            }

            if (i) {
                cand.push_back(A[i-1]);
            }

            for (int v = 0; v < cand.size(); ++v) {
                int now = cnt;
                int low = max(0, i-1);
                int up = min(N-1, i+1);
                for (int j = low; j <= up; ++j) {
                    now -= checkPlus(A, j);
                }

                A[i] = cand[v];
                for (int j = low; j <= up; ++j) {
                    now += checkPlus(A, j);
                }

                ans = min(ans, now);
                A[i] = tmp;
            }
        }
        cout << ans << endl;
    }

    return 0;
}