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

void checkPos(VI& num, int pos) {
    if (num[pos] == -1) {
        cout << "? " << pos << endl;
        int r;
        cin >> r;
        num[pos] = r;
    }
}

int main()
{
    int N;
    cin >> N;

    const int INF = 1000000000;
    VI num(N+2, -1);
    num[0] = num[N+1] = INF;

    int low = 1;
    int up = N;
    int ans = 0;

    while (low <= up) {
        int mid = (low+up) / 2;
        checkPos(num, mid);
        checkPos(num, mid+1);
        checkPos(num, mid-1);

        if (num[mid] > num[mid+1]) {
            low = mid+1;
        } else if (num[mid] > num[mid-1]) {
            up = mid-1;
        } else {
            ans = mid;
            break;
        }
    }

    cout << "! " << ans << endl;

    return 0;
}
