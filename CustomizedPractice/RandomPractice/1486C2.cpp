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

int findMaxPos(int s, int e, int pivot) {
    if (pivot == e) {
        int low = s+1;
        int up = pivot-1;
        int ret = s;

        while (low <= up) {
            int mid = (low+up) / 2;
            int r;

            cout << "? " << mid << " " << pivot << endl;
            cin >> r;

            if (r == pivot) {
                ret = mid;
                low = mid+1;
            } else {
                up = mid-1;
            }
        }

        return ret;
    } else {
        int low = pivot+1;
        int up = e-1;
        int ret = e;

        while (low <= up) {
            int mid = (low+up) / 2;
            int r;

            cout << "? " << pivot << " " << mid << endl;
            cin >> r;

            if (r == pivot) {
                ret = mid;
                up = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ret;
    }
}

int main()
{
    int N;
    cin >> N;

    cout << "? " << 1 << " " << N << endl;
    int pivot;
    int r;
    cin >> pivot;

    if (pivot == 1) {
        int ans = findMaxPos(1, N, pivot);
        cout << "! " << ans << endl;
    } else {
        cout << "? " << 1 << " " << pivot << endl;
        cin >> r;
        if (r == pivot) {
            int ans = findMaxPos(1, pivot, pivot);
            cout << "! " << ans << endl;
        } else {
            int ans = findMaxPos(pivot, N, pivot);
            cout << "! " << ans << endl;
        }
    }


    return 0;
}
