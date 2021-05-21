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

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        int M;
        int A;
        int B;
        cin >> N >> M >> A >> B;

        VI T(M);
        for (int i = 0; i < M; ++i) {
            cin >> T[i];
        }

        sort(T.begin(), T.end());

        int ans = 0;
        int diff = abs(A-B);
        int low = 1;
        int up = min(diff-1, M);

        int finalTime = 0;
        finalTime = diff-1;
        if (B>A) {
            finalTime += A;
        } else {
            finalTime += (N-A+1);
        }

        while (low <= up) {
            int mid = (low+up)/2;

            VI ST(M, -1);
            bool ok = true;
            int cnt = 1;

            for (int i = mid-1; i >= 0; --i) {
                ST[i] = cnt++;
            }

            for (int i = 0; i < mid; ++i) {
                if (finalTime-ST[i] < T[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                ans = mid;
                low = mid+1;
            } else {
                up = mid-1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}