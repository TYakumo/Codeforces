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
    long long A;
    long long B;
    long long C;
    long long D;
    cin >> A >> B >> C >> D;

    long long MAXV = 2*D+2;
    VLL pnt(MAXV);
    VLL comb(MAXV);
    VLL accComb(MAXV);

    for (long long v = B; v <= C; ++v) {
        long long from = v+A;
        long long to = v+B;

        ++pnt[from];
        --pnt[to+1];
    }

    long long acc = 0;
    for (long long v = 1; v < MAXV; ++v) {
        acc += pnt[v];
        comb[v] = acc;
        accComb[v] = accComb[v-1] + comb[v];
    }

    long long ans = 0;

    for (long long v = C; v <= D; ++v) {
        ans += (accComb.back() - accComb[v]);
    }

    cout << ans << endl;

    return 0;
}