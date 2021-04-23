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

VI genComb(int target, int num, int maxVal) {
    if (num == 1) {
        if (maxVal >= target) {
            return {target};
        } else {
            return {};
        }
    }

    if (target == 0 || num == 0) {
        return {};
    }

    for (int v = num; v <= maxVal; ++v) {
        int low = (1 + num-1)*(num-1)/2;
        int up = (v-1 + (v-1-num+2))*(num-1)/2;
        int remain = target - v;

        if (remain >= low && remain <= up) {
            VI ret = genComb(remain, num-1, v-1);
            if (ret.size()) {
                ret.push_back(v);
                return ret;
            }
        }
    }

    return {};
}

int main()
{
    int TC;

    cin >> TC;

    for (int tc = 1; tc <= TC; tc++) {
        int N;
        int S;
        int L;
        int R;

        cin >> N >> L >> R >> S;

        VI ans = genComb(S, R-L+1, N);

        if (ans.size() == 0) {
            cout << -1 << endl;
        } else {
            VI used(N+1);
            DI wholeAns;
            for (int i = 0; i < ans.size(); ++i) {
                wholeAns.push_back(ans[i]);
                used[ans[i]] = 1;
            }

            int l = 0;
            for (int i = 1; i <= N; ++i) {
                if (used[i] == 0) {
                    if (l < L-1) {
                        wholeAns.push_front(i);
                        ++l;
                    } else {
                        wholeAns.push_back(i);
                    }
                }
            }

            cout << wholeAns[0];

            for (int i = 1; i < wholeAns.size(); ++i) {
                cout << " " << wholeAns[i];
            }
            cout << endl;
        }
    }

    return 0;
}
