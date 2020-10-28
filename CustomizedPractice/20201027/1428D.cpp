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
using DI = deque <int>;
using VVI = vector <VI>;
using VLL = vector <long long>;

int main() {
    int N;
    cin >> N;

    VI A(N);
    VI matched(N);

    DI availRow;
    set <int> oneRow;
    map <int, int> colMap;
    map <int, int> colNotOneMap;

    // for 1 => take one row
    // for 2 => take two column
    // for 3 => take two rows
    for (int i = 0; i < N; ++i) {
        availRow.push_back(i);
    }

    VVI ans;

    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    bool mat = true;
    for (int i = N-1; i >= 0; --i) {
        if (A[i] == 1) {
            if (!availRow.empty()) {
                int chosenRow = availRow.back();
                ans.push_back({chosenRow+1, i+1});
                availRow.pop_back();

                colMap[chosenRow] = i;
                oneRow.insert(chosenRow);
            } else {
                mat = false;
                break;
            }
        } else if (A[i] == 2) {
            // match queOne
            if (!oneRow.empty()) {
                int chosenRow = *oneRow.begin();
                oneRow.erase(oneRow.begin());

                ans.push_back({chosenRow+1, i+1});
                colNotOneMap[chosenRow] = i;
            } else {
                mat = false;
                break;
            }
        } else if (A[i] == 3) {
            if (!availRow.empty() && (!colMap.empty() || !colNotOneMap.empty())) {
                int chosenRow = availRow.back();
                availRow.pop_back();
                auto iter = !colNotOneMap.empty() ? colNotOneMap.begin() : colMap.begin();

                ans.push_back({chosenRow+1, i+1});
                ans.push_back({chosenRow+1, iter->second+1});

                if (oneRow.find(iter->first) != oneRow.end()) {
                    oneRow.erase(oneRow.find(iter->first));
                }

                if (!colNotOneMap.empty()) {
                    colNotOneMap.erase(iter);
                } else {
                    colMap.erase(iter);
                }
                colNotOneMap[chosenRow] = i;
            } else {
                mat = false;
                break;
            }
        }
    }

    if (!mat) {
        cout << -1 << endl;
    } else {
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); ++i) {
            cout << ans[i][0] << " " << ans[i][1] << endl;
        }
    }

    return 0;
}