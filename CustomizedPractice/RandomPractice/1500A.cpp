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

int main() {
    int N;
    cin >> N;

    VI A(N);
    VI ans;
    int maxVal = 0;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        maxVal = max(maxVal, A[i]);
    }

    VVI comb(maxVal*2+10);

    // by pigeon holes principle => O(min(N^2, maxVal*2))
    for (int i = 1; i < N && ans.empty(); ++i) {
        for (int j = 0; j < i && ans.empty(); ++j) {
            int tot = A[i] + A[j];
            if (comb[tot].size() == 0) {
                comb[tot] = {i, j};
            } else {
                VI other = comb[tot];

                if (other[0] != i && other[0] != j && other[1] != i && other[1] != j) {
                    ans.push_back(i+1);
                    ans.push_back(j+1);
                    ans.push_back(other[0]+1);
                    ans.push_back(other[1]+1);
                }

                comb[tot] = {i, j};
            }
        }
    }

    if (ans.empty()) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
    }


    return 0;
}