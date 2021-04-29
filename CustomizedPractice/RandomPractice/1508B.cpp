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

    for (int tc = 0; tc < TC; ++tc) {
        int N;
        const long long INF = 4*1000000000LL * 1000000000LL;
        long long K;
        cin >> N >> K;

        --K;
        VLL comb(N+1);
        VLL acc(N+1);

        comb[0] = comb[1] = acc[0] = 1;
        acc[1] = 2;

        for (int n = 2; n <= N; ++n) {
            // comb[n] = sigma comb[1 ... n-1]
            comb[n] = acc[n-1];
            acc[n] = comb[n] + acc[n-1];
            if (acc[n] >= INF) {
                for (int nn = n+1; nn <= N; ++nn) {
                    acc[nn] = comb[nn] = INF;
                }
                break;
            }
        }



        VI ans;
        int offset = 0;

        for (int n = 0; n < N; ) {
            int low = 1;
            int up = N-n;
            int cho = -1;

            while (low <= up) {
                int mid = (low + up) / 2;

                int remain = (N-n) - mid;
                long long sum = acc[N-n-1] - acc[remain]; // sigma comb[N-n-1 ... N-n-mid]
                if (acc[N-n-1] == INF && acc[N-n-1] == comb[N-n-1] && mid != 1) {
                    sum = INF;
                }

                if (sum <= K) {
                    low = mid+1;
                    cho = mid;
                } else {
                    up = mid-1;
                }
            }

            if (cho == -1) {
                break;
            }

            K -= acc[N-n-1] - acc[N-n-cho];
            for (int p = 0; p < cho; ++p) {
                int r = cho-p+offset;
                ans.push_back(r);
            }

            n += cho;
            offset = n;
        }

        if (K != 0) {
            ans.clear();
        }

        if (ans.size() != N) {
            cout << -1 << endl;
        } else {
            cout << ans[0];

            for (int i = 1; i < ans.size(); ++i) {
                cout << " " << ans[i];
            }
            cout << endl;
        }
    }

    return 0;
}
