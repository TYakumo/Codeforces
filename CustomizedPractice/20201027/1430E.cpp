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

void mergeSort(VI& arr, VI& tmp, int start, int end, long long& ans) {
    if (start >= end) {
        return ;
    }

    int mid = (start+end) / 2;
    mergeSort(arr, tmp, start, mid, ans);
    mergeSort(arr, tmp, mid+1, end, ans);

    int arrCnt = start;
    int s1 = start;
    int s2 = mid+1;
    long long rcnt = 0;

    while (s1 <= mid && s2 <= end) {
        if (arr[s1] <= arr[s2]) {
            tmp[arrCnt++] = arr[s1++];
            ans += rcnt;
        } else {
            tmp[arrCnt++] = arr[s2++];
            ++rcnt;
        }
    }

    while (s1 <= mid) {
        tmp[arrCnt++] = arr[s1++];
        ans += rcnt;
    }

    while (s2 <= end) {
        tmp[arrCnt++] = arr[s2++];
    }

    arrCnt = start;
    while (arrCnt <= end) {
        arr[arrCnt] = tmp[arrCnt];
        ++arrCnt;
    }
}

int main() {
    int N;
    string S;
    string RS;

    cin >> N >> S;
    RS = S;
    reverse(RS.begin(), RS.end());

    VVI idxMap(26);
    VI idx(26);
    VI arr(S.size());
    VI tmp(S.size());

    for (int i = 0; i < S.size(); ++i) {
        idxMap[S[i]-'a'].push_back(i);
    }

    for (int i = 0; i < RS.size(); ++i) {
        arr[i] = idxMap[RS[i]-'a'][idx[RS[i]-'a']];
        ++idx[RS[i]-'a'];
    }

    // compute inversion
    long long ans = 0;
    mergeSort(arr, tmp, 0, S.size()-1, ans);

    cout << ans << endl;

    return 0;
}