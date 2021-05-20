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

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

VI getVec(int x, int y, int x2, int y2) {
    int dx = x2-x;
    int dy = y2-y;
    int g = abs(gcd(dx, dy));

    dx /= g;
    dy /= g;

    if (dx == 0 && dy != 0) {
        dy /= abs(dy);
    }

    if (dy == 0 && dx != 0) {
        dx /= abs(dx);
    }

    return {dx, dy};
}

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        cin >> N;

        VVI p(N, VI(4));
        map <VI, long long> cnt;

        for (int i = 0; i < N; ++i) {
            cin >> p[i][0] >> p[i][1] >> p[i][2] >> p[i][3];
            VI vec = getVec(p[i][0], p[i][1], p[i][2], p[i][3]);

            ++cnt[vec];
        }

        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            VI vec = getVec(p[i][0], p[i][1], p[i][2], p[i][3]);
            vec[0] = -vec[0];
            vec[1] = -vec[1];

            ans += cnt[vec];
        }

        cout << ans/2 << endl;
    }

    return 0;
}