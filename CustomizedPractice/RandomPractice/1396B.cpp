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
using VVVLL = vector <VVLL>;
using UMI = unordered_map<int, int>;
using UMLL = unordered_map<long long, long long>;
using VS = vector <string>;
using VC = vector <char>;
using DI = deque <int>;

int main()
{
    int TC;
    cin >> TC;

    while (TC--) {
        int N;
        cin >> N;

        VI A(N);
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            sum += A[i];
        }

        sort(A.begin(), A.end());

        if (sum%2 || (A.back() > sum-A.back())) {
            cout << "T" << endl;
        } else {
            cout << "HL" << endl;
        }
    }


    return 0;
}
