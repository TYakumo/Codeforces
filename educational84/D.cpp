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
using namespace std;

using VI = vector <int>;
using VVI = vector <VI>;
const int UNVISITED = -100;
const int VISITED = 1;

int gcd(int a, int b) {
    return b ? gcd(b, a%b) : a;
}

void getDivisors(set <int>& divisors, int v) {
    divisors.insert(1);
    int sq = sqrt(v);

    for (int n = 1; n <= sq; ++n) {
        if (v % n == 0) {
            divisors.insert(n);
            divisors.insert(v/n);
        }
    }
}

int main() {
    int TC;

    cin >> TC;

    while (TC--) {
        int N;
        cin >> N;

        VI P(N);
        VI C(N);
        VI R(N, UNVISITED);
        VVI groups;
        set <int> divisors;

        for (int i = 0; i < N; ++i) {
            cin >> P[i];
            --P[i];
        }

        for (int i = 0; i < N; ++i) {
            cin >> C[i];
        }

        for (int i = 0; i < N; ++i) {
            if (R[i] == UNVISITED) {
                VI visited;
                visited.push_back(i);
                R[i] = VISITED;

                for (int j = 0; j < visited.size(); ++j) {
                    int nextp = P[visited[j]];

                    if (R[nextp] != UNVISITED) {
                        break;
                    } else {
                        visited.push_back(nextp);
                    }

                    R[nextp] = VISITED;
                }

                groups.push_back(visited);
                getDivisors(divisors, (int)visited.size());
            }
        }

        auto iter = divisors.begin();
        int ans = N;

        while (iter != divisors.end()) {
            int div = *iter;

            for (int g = 0; g < groups.size() && ans == N; ++g) {
                if (gcd(groups[g].size(), div) == div) {
                    for (int i = 0; i < div && ans == N; ++i) {
                        int now = (i + div)%groups[g].size();
                        int oriid = groups[g][i];
                        bool ok = true;

                        while (now != i) {
                            int nowid = groups[g][now];

                            if (C[nowid] != C[oriid]) {
                                ok = false;
                                break;
                            }
                            now = (now+div)%groups[g].size();
                        }

                        if (ok) {
                            ans = div;
                            break;
                        }
                    }
                }
            }
            ++iter;
        }

        cout << ans << endl;
    }

    return 0;
}