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
    int N;
    cin >> N;
    VI A(N);
    int tot = 0;
    int oddIdx = -1;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        tot += A[i];
    }

    VI dp(tot+1);
    dp[0] = 1;

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        for (int v = sum; v >= 0; --v) {
            if (dp[v]) {
                dp[v+A[i]] = 1;
            }
        }
        sum += A[i];
    }

    if (tot%2 != 0 || dp[tot/2] == 0) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;

        while (oddIdx == -1) {
            for (int i = 0; i < N; ++i) {
                if (A[i]%2 == 1) {
                    oddIdx = i;
                    break;
                }
            }
            if (oddIdx != -1) {
                break;
            }
            for (int i = 0; i < N; ++i) {
                A[i] /= 2;
            }
        }

        cout << oddIdx+1 << endl;
    }

    return 0;
}