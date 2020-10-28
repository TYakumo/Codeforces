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
using VLL = vector <long long>;

int main() {
    int TC;

    cin >> TC;

    while (TC--) {
        int N;
        string S;
        cin >> N >> S;
        VI blocks;
        int now = 0;
        int ans = 0;

        while (now < N) {
            int st = now;

            while (now < N && S[st] == S[now]) {
                ++now;
            }

            int len = now-st;
            blocks.push_back(len);
        }

        now = 0;
        int cho = 0;

        while (now < blocks.size()) {
            ++ans;
            cho = max(cho, now);

            while (cho < blocks.size() && blocks[cho] == 1) {
                ++cho;
            }

            if (cho == blocks.size()) {
                ++now;
            } else {
                --blocks[cho];
            }

            ++now;
        }

        cout << ans << endl;
    }

    return 0;
}