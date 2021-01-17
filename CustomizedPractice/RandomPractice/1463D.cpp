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
using VVI = vector <VI>;
using VLL = vector <long long>;
using USI = unordered_set<int>;

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        cin >> N;
        int tot = 2*N;

        VI B(N);
        VI BP;
        USI bset;

        for (int i = 0; i < N; ++i) {
            cin >> B[i];
            bset.insert(B[i]);
        }

        for (int v = 1; v <= tot; ++v) {
            if (bset.find(v) == bset.end()) {
                BP.push_back(v);
            }
        }

        sort(B.begin(), B.end());
        sort(BP.begin(), BP.end());

        int low = 1;
        int up = N;
        int frontLength = 0;

        while (low <= up) {
            int mid = (low+up) / 2;
            bool pass = true;

            int backStart = N-mid;

            for (int i = 0; i < mid; ++i) {
                if (B[i] > BP[backStart+i]) {
                    pass = false;
                    break;
                }
            }

            if (pass) {
                frontLength = mid;
                low = mid+1;
            } else {
                up = mid-1;
            }
        }

        low = 1;
        up = N;
        int backLength = 0;

        while (low <= up) {
            int mid = (low+up) / 2;
            bool pass = true;

            int backStart = N-mid;

            for (int i = 0; i < mid; ++i) {
                if (BP[i] > B[backStart+i]) {
                    pass = false;
                    break;
                }
            }

            if (pass) {
                backLength = mid;
                low = mid+1;
            } else {
                up = mid-1;
            }
        }

        int minLen = N-backLength;
        int maxLen = frontLength;

        cout << max(0, maxLen-minLen+1) << endl;
    }

    return 0;
}