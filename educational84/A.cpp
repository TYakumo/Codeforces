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

int main() {
    int TC;

    cin >> TC;

    while (TC--) {
        long long N;
        long long K;

        cin >> N >> K;

        N -= K;

        if (N%2 == 0 && N >= 0) {
            long long num = N/2;
            long long tot = (K * (K-1)) / 2;

            if (num >= tot) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }

        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}