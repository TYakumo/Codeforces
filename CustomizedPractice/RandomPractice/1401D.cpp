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

int main()
{
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        int M;
        cin >> N;

        VVI adja(N);
        VVI cadja(N);
        VI used(N);

        for (int i = 1; i < N; ++i) {
            int f;
            int t;
            cin >> f >> t;
            --f;
            --t;
            adja[f].push_back(t);
            adja[t].push_back(f);
        }

        VLL ccnt(N, 1);
        deque <int> que;
        deque <int> order;
        que.push_back(0);

        while (!que.empty()) {
            int now = que.front();
            que.pop_front();
            used[now] = 1;
            order.push_back(now);

            for (int i = 0; i < adja[now].size(); ++i) {
                int to = adja[now][i];

                if (!used[to]) {
                    cadja[now].push_back(to);
                    que.push_back(to);
                }
            }
        }

        reverse(order.begin(), order.end());
        while (!order.empty()) {
            int now = order.front();
            order.pop_front();
            for (int j = 0; j < cadja[now].size(); ++j) {
                int t = cadja[now][j];
                ccnt[now] += ccnt[t];
            }
        }

        VLL w;

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < cadja[i].size(); ++j) {
                int t = cadja[i][j];
                w.push_back(ccnt[t] * (N-ccnt[t]));
            }
        }

        cin >> M;
        VLL p(M);
        for (int i = 0; i < M; ++i) {
            cin >> p[i];
        }

        const long long MOD = 1000000000+7;
        sort(w.begin(), w.end(), greater<long long>());
        sort(p.begin(), p.end(), greater<long long>());
        VLL np;

        if (p.size() > w.size()) {
            int diff = p.size()-w.size();
            long long mul = 1;
            for (int i = 0; i <= diff; ++i) {
                mul = (mul*p[i])%MOD;
            }

            np.push_back(mul);

            for (int i = diff+1; i < p.size(); ++i) {
                np.push_back(p[i]);
            }
        } else {
            np = p;
        }

        long long ans = 0;
        for (int i = 0; i < w.size(); ++i) {
            long long pmul = i < np.size() ? np[i] : 1;
            long long wmod = w[i]%MOD;
            ans += (wmod * pmul)%MOD;
            ans %= MOD;
        }

        cout << ans << endl;
    }


    return 0;
}
