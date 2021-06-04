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
        int N;
        int M;
        cin >> N >> M;

        VVLL p(2, VLL(N));
        VVLL hp(2, VLL(N));
        VVI adja(N);
        VVI cadja(N);
        VI used(N);

        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < N; ++j) {
                cin >> p[i][j];
            }
        }

        for (int i = 1; i < N; ++i) {
            int f;
            int t;
            cin >> f >> t;
            --f;
            --t;
            adja[f].push_back(t);
            adja[t].push_back(f);
        }

        deque <int> que;
        VI order;
        que.push_back(0);
        used[0] = 1;

        while (!que.empty()) {
            int now = que.front();
            que.pop_front();
            order.push_back(now);

            for (int i = 0; i < adja[now].size(); ++i) {
                int nextv = adja[now][i];

                if (used[nextv] == 0) {
                    cadja[now].push_back(nextv);
                    used[nextv] = 1;
                    que.push_back(nextv);
                }
            }
        }

        reverse(order.begin(), order.end());
        bool ok = true;

        for (int i = 0; i < order.size(); ++i) {
            int now = order[i];
            hp[1][now] = p[0][now];

            for (int j = 0; j < cadja[now].size(); ++j) {
                int nextv = cadja[now][j];
                hp[0][now] += hp[0][nextv];
                hp[1][now] += hp[1][nextv];
            }

            // h[now] == (hp[0][now]+diff) - (hp[1][now]-diff)
            // h[now] == hp[0][now]-hp[1][now]+2diff
            long long diff = p[1][now] - (hp[0][now]-hp[1][now]);

            if (diff < 0 || diff%2 != 0) {
                ok = false;
                break;
            } else {
                diff /= 2;
                if (diff > hp[1][now]) {
                    ok = false;
                    break;
                }
                hp[0][now] += diff;
                hp[1][now] -= diff;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }

    return 0;
}