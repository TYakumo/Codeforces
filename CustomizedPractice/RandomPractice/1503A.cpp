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
using VC = vector <char>;
using VS = vector <string>;

int main() {
    int TC;

    cin >> TC;

    while (TC--) {
        int N;
        string S;
        cin >> N >> S;

        int cnt = 0;
        int pcnt = 0;

        for (int i = 0; i < S.size(); ++i) {
            if (S[i] == '0') {
                ++cnt;
            } else {
                ++pcnt;
            }
        }

        if (cnt%2 == 0 && S[0] == '1' && S.back() == '1') {
            VS ans(2);
            int target = pcnt/2;

            for (int i = 0; i < 2; ++i) {
                ans[i] = S;

                int nowCnt = 0;
                for (int j = 0; j < N; ++j) {
                    if (S[j] == '1') {
                        if (nowCnt < target) {
                            ans[i][j] = '(';
                        } else {
                            ans[i][j] = ')';
                        }
                        ++nowCnt;
                    }
                }
            }

            int nowCnt = 0;
            for (int i = 0; i < N; ++i) {
                if (S[i] == '0') {
                    ans[0][i] = nowCnt%2 == 0 ? ')' : '(';
                    ans[1][i] = nowCnt%2 == 0 ? '(' : ')';
                    ++nowCnt;
                }
            }

            cout << "YES" << endl;
            for (int i = 0; i < 2; ++i) {
                cout << ans[i] << endl;
            }

        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}