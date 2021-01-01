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
#include <cassert>
#include <limits>
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;
using VLL = vector <long long>;

class UnionAndFind {
    public:
    vector <int> groupSize;
    vector <int> groupParent;

    UnionAndFind (int gSize) {
        groupSize = vector<int> (gSize, 1);
        groupParent = vector<int> (gSize, -1);
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
        groupParent[x] = y;
    }
};


int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        int M;
        int K;
        long long ans = 2000000000000000000LL;

        cin >> N >> M >> K;

        VVI edges;

        for (int i = 0; i < M; ++i) {
            int f;
            int t;
            int c;
            cin >> f >> t >> c;
            --f;
            --t;
            c -= K;
            edges.push_back({c, f, t});
        }

        UnionAndFind ut(N);
        sort(edges.begin(), edges.end());
        int comp = N;
        int idx = 0;

        while (idx < edges.size()) {
            if (edges[idx][0] > 0) {
                break;
            }

            int f = edges[idx][1];
            int t = edges[idx][2];

            if (ut.findGroup(f) != ut.findGroup(t)) {
                ut.unionGroup(f, t);
                --comp;
            }

            if (comp == 1) {
                ans = min(ans, (long long)abs(edges[idx][0]));
            }
            ++idx;
        }

        if (idx < edges.size()) {
            long long res = 0;
            int cho = 0;

            while (idx < edges.size()) {
                int f = edges[idx][1];
                int t = edges[idx][2];

                if (ut.findGroup(f) != ut.findGroup(t)) {
                    ut.unionGroup(f, t);
                    res += abs(edges[idx][0]);
                    --comp;
                    ++cho;
                }

                if (comp == 1 && cho <= 1) {
                    ans = min(ans, (long long)edges[idx][0]);
                }
                ++idx;
            }

            if (cho > 0) {
                ans = min(ans, res);
            }
        }

        cout << ans << endl;
    }

    return 0;
}