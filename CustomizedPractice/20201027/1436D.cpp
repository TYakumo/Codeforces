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
    int N;
    cin >> N;

    VVI adja(N);
    VLL people(N);
    VLL peopleSum(N);
    VLL leafCnt(N);
    long long ans = 0;

    for (int i = 1; i < N; ++i) {
        int p;
        cin >> p;
        adja[--p].push_back(i);
    }

    for (int i = 0; i < N; ++i) {
        cin >> people[i];
        peopleSum[i] = people[i];
    }

    VI order;
    int front = 0;
    const int SRC = 0;

    order.push_back(SRC);
    while (front < order.size()) {
        int now = order[front++];

        if (adja[now].size() == 0) {
            leafCnt[now] = 1;
            ans = max(ans, people[now]);
        }

        for (int i = 0; i < adja[now].size(); ++i) {
            int nextv = adja[now][i];
            order.push_back(nextv);
        }
    }

    reverse(order.begin(), order.end());
    for (int i = 0; i < order.size(); ++i) {
        int now = order[i];
        for (int j = 0; j < adja[now].size(); ++j) {
            int child = adja[now][j];

            leafCnt[now] += leafCnt[child];
            peopleSum[now] += peopleSum[child];
        }
        ans = max(ans, (peopleSum[now] + leafCnt[now]-1) / leafCnt[now]);
    }

    cout << ans << endl;

    return 0;
}