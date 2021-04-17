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

int main()
{
    const int MAXVAL = 10000;
    VI np(MAXVAL);
    VI primes;

    for (int v = 2; v < MAXVAL; ++v) {
        if (np[v] == 0) {
            primes.push_back(v);

            for (int j = v*2; j < MAXVAL; j += v) {
                np[j] = 1;
            }
        }
    }

    int TC;

    cin >> TC;

    for (int tc = 1; tc <= TC; tc++) {
        long long N;
        int K;

        cin >> N >> K;
        int seg = 1;
        set <VI> fact;
        for (int i = 0; i < N; ++i) {
            long long val;
            cin >> val;

            long long sq = sqrt(val);
            VI factor;

            for (int j = 0; j < primes.size() && primes[j] <= sq; ++j) {
                int d = primes[j];
                int cnt = 0;
                while (val % d == 0) {
                    val /= d;
                    cnt ^= 1;
                }

                if (cnt) {
                    factor.push_back(d);
                }
            }

            if (val != 1) {
                factor.push_back(val);
            }

            if (fact.count(factor)) {
                ++seg;
                fact.clear();
            }

            fact.insert(factor);
        }

        cout << seg << endl;
    }

    return 0;
}
