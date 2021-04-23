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

void genAnswer(VI& used, VC& ans, int now) {
    ans.push_back((now+'a'));
    used[now] = 1;
    int K = used.size();
    bool nextCho = false;

    for (int i = 0; i < K; ++i) {
        if (used[i] == 0) {
            ans.push_back((i+'a'));
            ans.push_back((now+'a'));
            nextCho = true;
        }
    }

    if (!nextCho) {
        return ;
    }

    ans.pop_back();
    genAnswer(used, ans, ans.back()-'a');
    ans.push_back(now+'a');
}

int main()
{
    int N;
    int K;
    cin >> N >> K;

    VC ans;
    VI used(K);
    ans.push_back('a');
    genAnswer(used, ans, 0);

    cout << ans[0];
    --N;
    for (int i = 0; i < N; ++i) {
        cout << ans[i%(ans.size()-1)+1];
    }
    cout << endl;

    return 0;
}
