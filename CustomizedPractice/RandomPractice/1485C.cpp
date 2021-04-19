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

    for (int tc = 1; tc <= TC; tc++) {
        int A;
        int B;

        cin >> A >> B;

        // A MOD B = X => A = XB+X = X(B+1) = Xb
        // (3, 2), (4, 3)
        long long ans = 0;
        long long sq = sqrt(A);
        for (long long X = 1; X <= sq && X < B; ++X) {
            // Xb <= A && B > X && b <= B+1
            // X(X+1+b') <= A
            // X^2+X+b'X <= A
            // b=b'+X+1 => b' <= B+1-X-1
            long long remain = A-X*X-X;
            if (remain > 0) {
                ans += min(remain/X, B-X);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
