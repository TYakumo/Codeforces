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
const int INF = 100000000;

int main() {

    int N;
    int M;
    int K;

    cin >> N >> M >> K;

    VI X(K);
    VI Y(K);
    VI TX(K);
    VI TY(K);

    string ans;
    int maxX = 0;
    int lx = 0;
    int ly = 0;
    VI maxY(N+1);
    VI minY(N+1, INF);

    for (int i = 0; i < K; ++i) {
        cin >> X[i] >> Y[i];
    }

    for (int i = 0; i < K; ++i) {
        cin >> TX[i] >> TY[i];
        lx = max(lx, X[i]);
        ly = max(ly, Y[i]);
        maxX = max(maxX, TX[i]);
        maxY[TX[i]] = max(maxY[TX[i]], TY[i]);
        minY[TX[i]] = min(minY[TX[i]], TY[i]);
    }

    // normalized => (N+M-2), every node starts at (1, 1)
    // at most => M*N afterwards

    for (int i = 1; i < ly; ++i) {
        ans += "L";
    }

    for (int i = 1; i < lx; ++i) {
        ans += "U";
    }

    int dir = 1;
    int nowx = 1;
    int nowy = 1;

    for (int x = 1; x <= maxX; ++x) {
        if (maxY[x] != 0) { // contains target
            int finalTarget = nowy;
            string dirWord;

            if (nowy >= minY[x] && nowy <= maxY[x]) {
                if (maxY[x]-nowy < nowy-minY[x]) {
                    dir = 1;
                } else {
                    dir = -1;
                }

                if (dir == 1) {
                    while (nowy < maxY[x]) {
                        ans += "R";
                        ++nowy;
                    }

                    dir = -1;
                    dirWord = "L";
                    finalTarget = minY[x];
                } else {
                    while (nowy > minY[x]) {
                        ans += "L";
                        --nowy;
                    }

                    dir = 1;
                    dirWord = "R";
                    finalTarget = maxY[x];
                }
            } else if (nowy < minY[x]) {
                finalTarget = maxY[x];
                dir = 1;
                dirWord = "R";
            } else {
                finalTarget = minY[x];
                dir = -1;
                dirWord = "L";
            }

            // collecting remains
            while (nowy != finalTarget) {
                nowy += dir;
                ans += dirWord;
            }
        }

        if (x < maxX) {
            ans += "D";
        }
    }

    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}