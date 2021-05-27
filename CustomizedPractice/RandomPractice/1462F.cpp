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

template<class T>
class FenwickTree {
    vector <T> sum;
public:
    FenwickTree (int treeSize) {
        sum = move(vector<T>(treeSize+1));
    }

    void addVal(int idx, T val) {
        while (idx < sum.size()) {
            sum[idx] += val;
            idx += (idx & (-idx));
        }
    }

    T getVal(int idx) {
        if (idx <= 0) {
            return 0;
        }

        T ret = 0;

        while (idx) {
            ret += sum[idx];
            idx -= (idx & (-idx));
        }

        return ret;
    }

    T queryRange(int a, int b) {
        return getVal(b) - getVal(a-1);
    }
};

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        cin >> N;

        VVI pnt;
        VI start(N);
        UMI coor;

        for (int i = 0; i < N; ++i) {
            int l;
            int r;
            cin >> l >> r;
            pnt.push_back({l, 0, i});
            pnt.push_back({r, 1, i});
            start[i] = l;
        }

        sort(pnt.begin(), pnt.end());
        int pcnt = 0;
        for (int i = 0; i < pnt.size(); ++i) {
            if (i == 0 || pnt[i][0] != pnt[i-1][0]) {
                coor[pnt[i][0]] = ++pcnt;
            }
        }

        int cnt = 0;
        int theMax = 0;
        FenwickTree <int> ft(pcnt+10);

        for (int i = 0; i < pnt.size(); ++i) {
            if (pnt[i][1] == 0) {
                ++cnt;
            } else {
                int idx = pnt[i][2];
                int from = coor[start[idx]];
                int to = coor[pnt[i][0]];
                theMax = max(theMax, cnt + ft.queryRange(from, to));

                --cnt;
                ft.addVal(coor[pnt[i][0]], 1);
            }
        }

        cout << N-theMax << endl;


    }

    return 0;
}