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
#include <random>
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;
using VVVI = vector <VVI>;

using VD = vector <double>;
using VVD = vector <VD>;
using VVVD = vector <VVD>;

using VLL = vector <long long>;
using VVLL = vector <VLL>;
using UMI = unordered_map<int, int>;
using UMLL = unordered_map<long long, long long>;

using VS = vector <string>;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a%b) : a;
}

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        long long K;
        cin >> N >> K;

        long long g = 0;
        VLL v(N);
        for (int i = 0; i < N; ++i) {
            cin >> v[i];
        }

        for (int i = 1; i < N; ++i) {
            g = gcd(g, v[i]-v[0]);
        }

        cout << ((K-v[0])%g == 0 ? "YES" : "NO") << endl;
    }

    return 0;
}