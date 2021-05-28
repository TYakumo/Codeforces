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

bool solve(const VI& A) {
    int N = A.size();
    VI bakA = A;
    VI DP(N+5);
    VI RightOK(N+5);

    RightOK[N-1] = 1;
    for (int i = N-2; i >= 0; --i) {
        if (A[i] <= A[i+1]) {
            RightOK[i] = 1;
        } else {
            break;
        }
    }

    DP[0] = A[0];
    for (int i = 1; i < N; ++i) {
        DP[i] = min(DP[i-1], A[i]);
    }

    const int INF = 100000000;
    int preVal = -INF;
    for (int i = 0; i < N; ++i) {
        if (bakA[i] < preVal) {
            break;
        }

        if (i) {
            DP[i] = min(DP[i], DP[i-1]);
        }

        int used = min(DP[i], bakA[i]-preVal);
        bakA[i] -= used;
        DP[i] = used;


        bool rightGreater = (i == N-1) || (RightOK[i+1] && bakA[i] <= bakA[i+1]) ? true : false;

        if (rightGreater) {
            // cout << "GOT IT " << i << " " << bakA[i] << " " << RightOK[i+1] << endl;
            return true;
        }

        preVal = bakA[i];
    }

    return false;
}

int main()
{
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        cin >> N;

        VI A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        bool ok = solve(A);
        reverse(A.begin(), A.end());
        ok |= solve(A);

        cout << (ok ? "YES" : "NO") << endl;

    }

    return 0;
}
