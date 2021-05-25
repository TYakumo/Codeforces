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
#include <random>
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;
using VVVI = vector <VVI>;

using VD = vector <double>;
using VVD = vector <VD>;
using VVVD = vector <VVD>;

using VLL = vector <long long>;
using VVLL = vector <VLL>;
using UMI = unordered_map<int, int>;
using UMLL = unordered_map<long long, long long>;

using VS = vector <string>;

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        long long M;
        cin >> N >> M;

        VVLL A(2);
        VLL tmp(N);
        for (int i = 0; i < N; ++i) {
            cin >> tmp[i];
        }

        for (int i = 0; i < N; ++i) {
            int type;
            cin >> type;
            A[type-1].push_back(tmp[i]);
        }

        sort(A[0].begin(), A[0].end(), greater<long long>());
        sort(A[1].begin(), A[1].end(), greater<long long>());

        long long sum = 0;
        const long long INF = 1000000000LL * 1000;
        VLL acc(A[0].size()+1);
        for (int i = 1; i <= A[0].size(); ++i) {
            acc[i] = acc[i-1] + A[0][i-1];
        }

        int ans = -1;

        for (int i = 0; i <= A[1].size(); ++i) {
            if (i) {
                sum += A[1][i-1];
            }

            long long remain = M-sum;
            auto iter = lower_bound(acc.begin(), acc.end(), remain);

            if (iter != acc.end()) {
                int cost = (i*2) + (iter-acc.begin());
                if (ans == -1 || cost < ans) {
                    ans = cost;
                }
            }
        }

        cout << ans << endl;
    }

    return 0;
}