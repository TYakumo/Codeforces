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
        int N;
        cin >> N;

        VI S(N);
        VLL acc(N);
        VLL touch(N);
        for (int i = 0; i < N; ++i) {
            cin >> S[i];
        }

        long long ans = 0;
        long long sum = 0;

        for (int i = 0; i < N; ++i) {
            int target = (N-i-1);
            long long cost = 0;
            if (S[i] > target && target >= 2) {
                cost += (S[i]-target);
                S[i] = target;
            }

            sum += acc[i];
            touch[i] += sum;

            int far = i+S[i]+1;
            int near = i+2;
            if (S[i] >= 2) {
                if (near < N) {
                    ++acc[near];
                }
                if (far < N) {
                    --acc[far];
                }
                cost += S[i]-1;
                S[i] = 1;
            }

            cost -= touch[i];
            long long over = cost < 0 ? -cost : 0;
            if (i+1 < N) {
                touch[i+1] += over;
            }

            // ans += cost;
            ans += max(0LL, cost);
        }

        cout << ans << endl;
    }

    return 0;
}
