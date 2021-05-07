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

bool solve(long long A, long long B, long long now) {
    if (now == 0) {
        return true;
    }

    if (A > B) {
        return false;
    }

    if (__builtin_popcount(A) < __builtin_popcount(B)) {
        return false;
    }

    if ((A&now) != (B&now)) { // because B >= A => B&val == 1 & A&val == 0
        // make __builtin_popcount(A) == __builtin_popcount(B)
        A |= now;

        long long tmp = now/2;

        while (tmp && __builtin_popcount(A) > __builtin_popcount(B)) {
            if (A&tmp) {
                A -= tmp;
            }
            tmp /= 2;
        }

        return solve(A, B, now/2);
    }

    return solve(A-(A&now), B-(B&now), now>>1);
}

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        long long A;
        long long B;
        cin >> A >> B;
        const int UPPER = 31;

        cout << (solve(A, B, 1LL<<UPPER) ? "YES" : "NO") << endl;
    }

    return 0;
}