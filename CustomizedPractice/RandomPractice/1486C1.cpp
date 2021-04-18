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

int findMaxPos(int s, int e, int sec) {
    if (s==e) {
        return s;
    }

    if (s+1 == e) {
        cout << "? " << s << " " << e << endl;
        int r;
        cin >> r;
        if (r == e) {
            return s;
        } else {
            return e;
        }
    }

    int mid = (s+e) / 2;
    int r1;
    int r2;

    if (sec == -1) {
        cout << "? " << s << " " << e << endl;
        cin >> r1;
    } else {
        r1 = sec;
    }

    if (r1 <= mid) {
        if (s == mid) {
            return findMaxPos(mid+1, e, -1);
        }

        cout << "? " << s << " " << mid << endl;
        cin >> r2;

        if (r2 == r1) {
            return findMaxPos(s, mid, r2);
        } else {
            return findMaxPos(mid+1, e, -1);
        }
    } else {
        if (mid+1 == e) {
            return findMaxPos(s, mid, -1);
        }

        cout << "? " << mid+1 << " " << e << endl;
        cin >> r2;

        if (r2 == r1) {
            return findMaxPos(mid+1, e, r2);
        } else {
            return findMaxPos(s, mid, -1);
        }
    }
}

int main()
{
    int N;
    cin >> N;

    int ans = findMaxPos(1, N, -1);

    cout << "! " << ans << endl;

    return 0;
}
