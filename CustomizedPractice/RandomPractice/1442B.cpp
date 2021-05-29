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
        int M;
        cin >> N >> M;

        VI A(N);
        VI B(M);
        const long long MOD = 998244353;
        long long comb = 1;
        map <int, int> ASet;
        UMI ValMap;
        UMI BSet;
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
            ASet[i] = A[i];
            ValMap[A[i]] = i;
        }

        for (int i = 0; i < M; ++i) {
            cin >> B[i];
            BSet[B[i]] = 1;
        }

        for (int i = 0; i < M; ++i) {
            int idx = ValMap[B[i]];
            auto leftIter = ASet.find(idx);
            auto rightIter = ASet.find(idx);

            if (leftIter == ASet.begin()) {
                leftIter = ASet.end();
            } else {
                --leftIter;
            }

            ++rightIter;
            bool leftExist = leftIter != ASet.end() && BSet.count(leftIter->second) ? true : false;
            bool rightExist = rightIter != ASet.end() && BSet.count(rightIter->second) ? true : false;

            if (leftExist && rightExist) {
                comb = 0;
                break;
            } else if (leftExist) {
                if (rightIter != ASet.end()) {
                    ASet.erase(rightIter);
                } else {
                    comb = 0;
                    break;
                }
            } else if (rightExist) {
                if (leftIter != ASet.end()) {
                    ASet.erase(leftIter);
                } else {
                    comb = 0;
                    break;
                }
            } else {
                comb *= (leftIter != ASet.end())+(rightIter != ASet.end());
                comb %= MOD;
                if (leftIter != ASet.end()) {
                    ASet.erase(leftIter);
                } else if (rightIter != ASet.end()) {
                    ASet.erase(rightIter);
                } else {
                    comb = 0;
                    break;
                }
            }

            BSet.erase(BSet.find(B[i]));
        }



        cout << comb << endl;

    }

    return 0;
}
