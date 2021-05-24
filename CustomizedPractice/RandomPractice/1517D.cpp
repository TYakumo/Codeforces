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
using UMI = unordered_map<int, int>;
using UMLL = unordered_map<long long, long long>;

int main() {
    int N;
    int M;
    int K;
    cin >> N >> M >> K;
    VVVI W(2, VVI(N, VI(M)));
    for (int i = 0; i < 2; ++i) {
        int flag = i^1;
        for (int a = 0; a < N-i; ++a) {
            for (int b = 0; b < M-flag; ++b) {
                cin >> W[i][a][b];
            }
        }
    }

    if (K%2) {
        for (int i = 0; i < N; ++i) {
            cout << -1;
            for (int j = 1; j < M; ++j) {
                cout << " " << -1;
            }
            cout << endl;
        }
    } else {
        const int INF = 100000000;
        VVVI dp(K+1, VVI(N, VI(M, INF)));

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                dp[0][i][j] = 0;
            }
        }

        int target = K/2;
        for (int k = 1; k <= target; ++k) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    if (dp[k-1][i][j] == INF) {
                        continue;
                    }

                    const int dr[] = {1, -1, 0, 0};
                    const int dc[] = {0, 0, 1, -1};
                    const int dm[] = {1, 1, 0, 0};
                    const int odir[] = {0, 0, 2, 2};

                    for (int dir = 0; dir < 4; ++dir) {
                        int nr = i+dr[dir];
                        int nc = j+dc[dir];

                        if (nr >= 0 && nr < N
                        && nc >= 0 && nc < M) {
                            int orr = dir == 1 ? i-1 : i;
                            int orc = dir == 3 ? j-1 : j;
                            int wdir = odir[dir];
                            int newWeight = dp[k-1][i][j] + 2*W[dm[dir]][orr][orc];
                            dp[k][nr][nc] = min(dp[k][nr][nc], newWeight);
                        }
                    }
                }
            }
        }

        auto converter = [&INF](int v) { return v == INF ? -1 : v; };
        for (int i = 0; i < N; ++i) {
            cout << converter(dp[target][i][0]);
            for (int j = 1; j < M; ++j) {
                cout << " " << converter(dp[target][i][j]);
            }
            cout << endl;
        }
    }


    return 0;
}