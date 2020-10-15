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

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        cin >> N;

        VVI cho(N);
        VI matched(N, -1);
        int lastUnmatch = -1;

        for (int i = 0; i < N; ++i) {
            int n;
            cin >> n;

            bool marry = false;

            for (int j = 0; j < n; ++j) {
                int v;
                cin >> v;

                if (matched[--v] == -1) {
                    if (marry == false) {
                        matched[v] = i;
                        marry = true;
                    }
                }
            }

            if (!marry) {
                lastUnmatch = i;
            }
        }

        if (lastUnmatch != -1) {
            cout << "IMPROVE" << endl;
            for (int i = 0; i < N; ++i) {
                if (matched[i] == -1) {
                    cout << (lastUnmatch+1) << " " << (i+1) << endl;
                    break;
                }
            }
        } else {
            cout << "OPTIMAL" << endl;
        }
    }

    return 0;
}