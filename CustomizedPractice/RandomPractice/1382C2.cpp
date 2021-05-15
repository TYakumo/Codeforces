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

inline char getChar(const string& S, int l, int r, int inv, int idx) {
    if (r < l) {
        return ((S[l-idx]-'0')^inv) + '0';
    }
    return ((S[l+idx]-'0')^inv) + '0';
}

void solve(const string& S1, const string& S2, int l0, int r0, int inv0, int l1, int r1, int inv1, VI& ans) {
    int leng = abs(r0-l0)+1;
    int half = leng/2;

    if (leng == 1) {
        if (getChar(S1, l0, r0, inv0, 0) != getChar(S2, l1, r1, inv1, 0)) {
            ans.push_back(1);
        }
        return ;
    }

    bool match = true;
    for (int i = 0; i < half; ++i) {
        int idx = leng-1-i;

        if (getChar(S1, l0, r0, inv0, idx) != getChar(S2, l1, r1, inv1, idx)) {
            match = false;
            break;
        }
    }

    if (match) { // just half length
        int remain = leng-half;
        int nl0 = l0;
        int nr0 = l0+remain-1;

        if (r0 < l0) {
            nr0 = l0-remain+1;
        }

        int nl1 = l1;
        int nr1 = l1+remain-1;

        if (r1 < l1) {
            nr1 = l1-remain+1;
        }

        solve(S1, S2, nl0, nr0, inv0, nl1, nr1, inv1, ans);
    } else {
        int nl0 = l0;
        int nr0 = l0+half-1;

        if (r0 < l0) {
            nr0 = l0-half+1;
        }

        swap(l1, r1);
        int nl1 = l1;
        int nr1 = l1+half-1;

        if (r1 < l1) {
            nr1 = l1-half+1;
        }

        solve(S1, S2, nl0, nr0, inv0, nl1, nr1, inv1^1, ans);
        ans.push_back(leng);

        int remain = leng-half;
        swap(l1, r1);
        swap(l0, r0);
        nl0 = l0;
        nr0 = l0+remain-1;

        nl1 = l1;
        nr1 = l1+remain-1;

        if (r1 < l1) {
            nr1 = l1-remain+1;
        }

        if (r0 < l0) {
            nr0 = l0-remain+1;
        }
        solve(S1, S2, nl0, nr0, inv0^1, nl1, nr1, inv1, ans);
    }
}

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        string S1;
        string S2;
        cin >> N >> S1 >> S2;

        VI ans;
        solve(S1, S2, 0, N-1, 0, 0, N-1, 0, ans);

        cout << ans.size();

        for (int i = 0; i < ans.size(); ++i) {
            cout << " " << ans[i];
        }

        cout << endl;
    }

    return 0;
}