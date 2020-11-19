#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <queue>
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;
using VLL = vector <long long>;
using UMII = unordered_map<int, int>;

const long long MOD = 998244353;

class UnionAndFind {
    public:
    vector <int> groupSize;
    vector <int> groupParent;
    VI cho;

    UnionAndFind (int gSize) {
        groupSize = vector<int> (gSize, 1);
        groupParent = vector<int> (gSize, -1);
        cho = VI(gSize);
    }

    int findGroup(int n) {
        if (groupParent[n] == -1) {
            return n;
        }
        return groupParent[n] = findGroup(groupParent[n]);
    }

    void unionGroup(int x, int y) {
        y = findGroup(y);
        x = findGroup(x);

        if (x == y) {
            return ;
        }

        if (groupSize[x] > groupSize[y]) {
            swap(x, y);
        }

        groupSize[y] += groupSize[x];
        cho[y] += cho[x];
        groupParent[x] = y;
    }

    int incCnt(int n) {
        return cho[findGroup(n)];
    }

    int getCho(int n) {
        return cho[findGroup(n)];
    }

    int getRemain(int n) {
        return min(1, groupSize[findGroup(n)] - cho[findGroup(n)]);
    }
};

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        int K;
        cin >> N >> K;
        UMII amap;

        for (int i = 0; i < N; ++i) {
            int A;
            cin >> A;
            amap[A] = i;
        }

        UnionAndFind ut(N);
        VI mark(N);
        VI B(K);

        for (int i = 0; i < K; ++i) {
            cin >> B[i];
            int idx = amap[B[i]];
            mark[idx] = 1;
        }

        long long ans = 1;
        for (int i = 0; i < K && ans > 0; ++i) {
            int idx = amap[B[i]];
            mark[idx] = 0;

            // Av-1 or Av+1
            if (idx+1 < N && idx-1 >= 0) {
                int ng = ut.findGroup(idx+1);
                int pg = ut.findGroup(idx-1);

                if (!mark[ng] && !mark[pg]) {
                    ans = ans * (ut.getRemain(pg)+ut.getRemain(ng)) % MOD;
                    ut.unionGroup(idx, pg);
                    ut.unionGroup(idx, ng);
                } else if (!mark[pg]) {
                    ans = ans * (ut.getRemain(pg)) % MOD;
                    ut.unionGroup(idx, pg);
                } else if (!mark[ng]) {
                    ans = ans * (ut.getRemain(ng)) % MOD;
                    ut.unionGroup(idx, ng);
                } else {
                    ans = 0;
                    break;
                }

                ut.incCnt(idx);
            } else if (idx+1 < N) {
                int ng = ut.findGroup(idx+1);
                if (!mark[ng]) {
                    ans = ans * (ut.getRemain(ng)) % MOD;
                    ut.unionGroup(idx, ng);
                } else {
                    ans = 0;
                    break;
                }
            } else {
                int pg = ut.findGroup(idx-1);
                if (!mark[pg]) {
                    ans = ans * (ut.getRemain(pg)) % MOD;
                    ut.unionGroup(idx, pg);
                } else {
                    ans = 0;
                    break;
                }
            }
        }

        cout << (ans+MOD)%MOD << endl;
    }

    return 0;
}