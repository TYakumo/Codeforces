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


int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        string S;
        cin >> S;

        UMI cnt;
        for (int i = 0; i < S.size(); ++i) {
            ++cnt[S[i]];
        }

        int N;
        cin >> N;
        VI b(N);
        for (int i = 0; i < N; ++i) {
            cin >> b[i];
        }

        VI ans(N, -1);

        for (int ch = 'z'; ch >= 'a'; --ch) {
            int num = cnt[ch];

            VI dist(N);
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    if (ans[j] != -1) {
                        dist[i] += abs(i-j);
                    }
                }
            }

            int matched = 0;
            for (int i = 0; i < N; ++i) {
                if (ans[i] == -1 && dist[i] == b[i]) {
                    ++matched;
                }
            }

            if (matched <= num) {
                for (int i = 0; i < N; ++i) {
                    if (ans[i] == -1 && dist[i] == b[i]) {
                        ans[i] = ch;
                    }
                }
            }
        }


        string res;
        for (int i = 0; i < N; ++i) {
            // existence guaranteed
            res += (char)ans[i];
        }


        cout << res << endl;
    }

    return 0;
}