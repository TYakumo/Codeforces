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
    int TC;

    cin >> TC;

    for (int tc = 1; tc <= TC; tc++) {
        long long N;
        long long K;
        VLL ans;

        cin >> N >> K;

        long long BN = N;

        for (int i = 3; i < K; ++i) {
            --N;
            ans.push_back(1);
        }

        K = 3;
        long long mul = 1;

        while (N%2 == 0 && N>4) {
            N /= 2;
            mul *= 2;
        }

        if (N%2 == 0) {
            ans.push_back(mul);
            ans.push_back(mul);
            ans.push_back(mul*2);
        } else {
            ans.push_back(mul);
            ans.push_back(mul*(N/2));
            ans.push_back(mul*(N/2));
        }

        cout << ans[0];
        for (int i = 1; i < ans.size(); ++i) {
            cout << " " << ans[i];
        }
        cout << endl;
    }

    return 0;
}
