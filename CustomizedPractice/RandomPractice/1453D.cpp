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

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        long long K;
        cin >> K;

        if (K%2 == 1) {
            cout << -1 << endl;
        } else {
            K /= 2;
            VI ans;
            int tot = 0;

            if (K%2 == 1) {
                ans.push_back(0);
                ++tot;
            }

            for (long long b = 1; b <= 61; ++b) {
                long long bm = 1LL << b;
                if (K&bm) {
                    ans.push_back(b-1);
                    ans.push_back(0);
                    tot += (b+1);
                }
            }

            cout << tot << endl;
            string delimit;

            for (int i = 0; i < ans.size(); ++i) {
                cout << delimit << 1;
                delimit = " ";

                for (int j = 0; j < ans[i]; ++j) {
                    cout << " " << 0;
                }
            }
            cout << endl;
        }

    }

    return 0;
}