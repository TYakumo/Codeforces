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
    long long N;
    cin >> N;

    // R S P
    VVI A(2, VI(3));
    const int INF = 1000000010;
    int theMax = 0;
    int theMin = INF;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> A[i][j];
        }
    }

    theMax = min(A[0][0], A[1][1]) +  min(A[0][1], A[1][2]) +  min(A[0][2], A[1][0]);
    VI v(6);

    for (int i = 0; i < 6; ++i) {
        v[i] = i;
    }

    do {
        VVI VA = A;

        for (int st = 0; st < v.size(); ++st) {
            int type = v[st]/2;
            int mov = v[st]%2;

            if (mov == 0) {
                int minus = min(VA[0][type], VA[1][type]);
                VA[0][type] -= minus;
                VA[1][type] -= minus;
            } else {
                int atype = (type+2)%3;
                int minus = min(VA[0][type], VA[1][atype]);
                VA[0][type] -= minus;
                VA[1][atype] -= minus;
            }
        }

        int res = 0;
        for (int i = 0; i < 3; ++i) {
            res += min(VA[0][i], VA[1][(i+1)%3]);
        }

        theMin = min(theMin, res);
    } while (next_permutation(v.begin(), v.end()));

    cout << theMin << " " << theMax << endl;

    return 0;
}
