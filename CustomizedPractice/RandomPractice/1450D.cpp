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

const int INF = 1000000100;
inline int getMin(const VVI& theMin, int f, int t) {
    if (f == t) {
        return theMin[f][0];
    }

    int len = t-f+1;
    int logLen = 0;
    while ((1<<(logLen+1)) < len) {
        ++logLen;
    }

    t -= (1<<logLen);
    ++t;
    return min(theMin[f][logLen], theMin[t][logLen]);
}

inline bool checkOK(const VI& A) {
    UMI cnt;
    for (int i = 0; i < A.size(); ++i) {
        ++cnt[A[i]];
    }

    for (int i = 1; i <= A.size(); ++i) {
        if (cnt[i] != 1) {
            return false;
        }
    }

    return true;
}

int main()
{
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        cin >> N;

        int maxL = 0;
        while ((1<<maxL) < N) {
            ++maxL;
        }

        VVI theMin(N, VI(maxL+1, INF));
        VI A(N);

        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            theMin[i][0] = A[i];
        }

        for (int l = 1; l <= maxL; ++l) {
            for (int i = 0; i < N; ++i) {
                int j = i+(1<<(l-1));
                if (j < N) {
                    theMin[i][l] = min(theMin[i][l-1], theMin[j][l-1]);
                }
            }
        }

        int low = 2;
        int up = N;
        int start = N+1;
        int ok = checkOK(A);

        while (low <= up) {
            int mid = (low + up)/2;
            VI v;
            int maxIdx = -1;
            bool failed = false;

            for (int i = mid-1; i < N; ++i) {
                v.push_back(getMin(theMin, i-mid+1, i));
                if (maxIdx == -1 || v.back() > v[maxIdx]) {
                    maxIdx = v.size()-1;
                } else if (v.back() == v[maxIdx]) {
                    failed = true;
                    break;
                }
            }

            for (int i = 1; i <= maxIdx; ++i) {
                if (v[i] <= v[i-1]) {
                    failed = true;
                    break;
                }
            }

            for (int i = v.size()-2; i >= maxIdx; --i) {
                if (v[i+1] >= v[i]) {
                    failed = true;
                    break;
                }
            }

            failed |= !checkOK(v);
            if (!failed) {
                up = mid-1;
                start = mid;
            } else {
                low = mid+1;
            }
        }


        cout << ok;
        for (int k = 2; k < start; ++k) {
            cout << 0;
        }

        for (int k = start; k <= N; ++k) {
            cout << 1;
        }

        cout << endl;
    }

    return 0;
}
