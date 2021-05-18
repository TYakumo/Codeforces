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
using DVI = deque <VI>;
using VDVI = vector <DVI>;

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        cin >> N;
        VLL d(2*N);
        UMLL cnt;
        bool failed = false;
        for (int i = 0; i < 2*N; ++i) {
            cin >> d[i];
            ++cnt[d[i]];

            if (d[i]%2) {
                failed = true;
            }
        }

        sort(d.begin(), d.end());
        VLL A;
        for (int i = 0; i < d.size(); ++i) {
            if (i == 0 || d[i] != d[i-1]) {
                if (cnt[d[i]] != 2) {
                    failed = true;
                    break;
                }

                A.push_back(d[i]);
            }
        }

        if (failed) {
            cout << "NO" << endl;
        } else {
            long long sum = 0;
            for (int i = 1; i < A.size(); ++i) {
                long long diff = (A[i]-A[0])/2 + sum;
                if (diff % i != 0 || diff == 0) {
                    failed = true;
                    break;
                } else {
                    long long plus = diff/i;
                    sum += plus;
                }
            }

            // X*N + sum == A[0]/2
            long long remain = A[0]/2 - sum;

            if (failed || remain <= 0 || remain%N != 0) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        }
    }

    return 0;
}