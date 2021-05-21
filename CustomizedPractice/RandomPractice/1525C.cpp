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
using DVI = deque <VI>;
using VDVI = vector <DVI>;

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        long long M;
        cin >> N >> M;

        VVLL A(N, VLL(3));
        for (int i = 0; i < N; ++i) {
            cin >> A[i][0];
            A[i][2] = i;
        }

        VVVLL P(2);
        for (int i = 0; i < N; ++i) {
            char ch;
            cin >> ch;

            A[i][1] = (ch == 'R');
            P[A[i][0]%2].push_back(A[i]);
        }

        VLL ans(N, -1);

        for (int i = 0; i < 2; i++) {
            sort(P[i].begin(), P[i].end());
            VVLL stk;

            for (int k = 0; k < P[i].size(); ++k) {
                stk.push_back(P[i][k]);

                int j = stk.size()-1;
                if (stk.size() >= 2) {
                    if (stk[j-1][1] == 1 && stk[j][1] == 0) {
                        long long diff = stk[j][0] - stk[j-1][0];
                        ans[stk[j][2]] = ans[stk[j-1][2]] = diff/2;
                        stk.pop_back();
                        stk.pop_back();
                    } else if (stk.size() == 2 && stk[j-1][1] == 0 && stk[j][1] == 0) {
                        long long diff = stk[j][0] + stk[j-1][0];
                        ans[stk[j][2]] = ans[stk[j-1][2]] = diff/2;
                        stk.pop_back();
                        stk.pop_back();
                    }
                }
            }

            while (stk.size() > 1) {
                int j = stk.size()-1;
                if (stk[j-1][1] == 1 && stk[j][1] == 0) {
                    long long diff = stk[j][0] - stk[j-1][0];
                    ans[stk[j][2]] = ans[stk[j-1][2]] = diff/2;
                    stk.pop_back();
                    stk.pop_back();
                } else if (stk[j-1][1] == 1 && stk[j][1] == 1) {
                    long long diff = 2*(M-stk[j][0]) + stk[j][0] - stk[j-1][0];
                    ans[stk[j][2]] = ans[stk[j-1][2]] = diff/2;
                    stk.pop_back();
                    stk.pop_back();
                } else if (stk.size() == 2)  {
                    long long diff = 2*(M-stk[j][0]) + stk[j][0] + stk[j-1][0];
                    ans[stk[j][2]] = ans[stk[j-1][2]] = diff/2;
                    stk.pop_back();
                    stk.pop_back();
                } else {
                    long long diff = stk[j][0] + stk[j-1][0];
                    ans[stk[j][2]] = ans[stk[j-1][2]] = diff/2;
                    stk.pop_back();
                    stk.pop_back();
                }
            }
        }

        cout << ans[0];
        for (int i = 1; i < ans.size(); ++i) {
            cout << " " << ans[i];
        }
        cout << endl;
    }

    return 0;
}