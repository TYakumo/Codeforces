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

        VVI v(N, VI(3));

        for (int i = 0; i < N; ++i) {
            cin >> v[i][0] >> v[i][1];

            if (v[i][0] < v[i][1]) {
                swap(v[i][0], v[i][1]);
            }
            v[i][2] = i;
        }

        sort(v.begin(), v.end());
        map <int, int> idxMapping;
        VI ans(N, -1);

        for (int i = 0; i < N; ) {
            int j = i;
            while (j < N && v[j][0] == v[i][0]) {
                ++j;
            }

            for (int k = i; k < j; ++k) {
                auto iter = idxMapping.upper_bound(-v[k][1]);
                if (iter != idxMapping.end()) {
                    ans[v[k][2]] = iter->second+1;
                }
            }

            for (int k = i; k < j; ++k) {
                idxMapping[-v[k][1]] = v[k][2];
            }

            i = j;
        }

        cout << ans[0];
        for (int i = 1; i < ans.size(); ++i) {
            cout << " " << ans[i];
        }
        cout << endl;
    }

    return 0;
}