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
        cin >> N;

        VI A(2*N);
        UMI cnt;

        for (int i = 0; i < A.size(); ++i) {
            cin >> A[i];
            ++cnt[A[i]];
        }

        sort(A.begin(), A.end());
        VVI ans;

        for (int i = 0; i < A.size()-1; ++i) {
            UMI ncnt = cnt;

            VVI res;
            int sum = A.back();
            --ncnt[A.back()];
            --ncnt[A[i]];
            res.push_back({A[i], A.back()});


            for (int j = A.size()-2; j >= 0; --j) {
                if (ncnt[A[j]]) {
                    --ncnt[A[j]];
                    int target = sum - A[j];

                    if (ncnt[target] > 0) {
                        --ncnt[target];
                        res.push_back({target, A[j]});
                    } else {
                        break;
                    }

                    sum = max(target, A[j]);
                }
            }

            if (res.size() == N) {
                ans = res;
                break;
            }
        }

        if (ans.empty()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << ans[0][0] + ans[0][1] << endl;
            for (int i = 0; i < ans.size(); ++i) {
                cout << ans[i][0] << " " << ans[i][1] << endl;
            }
        }
    }

    return 0;
}