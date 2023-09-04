#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e5 + 10;

int s[N];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int arr[n];
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
//        mp[arr[i]] = i;
    }
    int l = 0, r = 0;
    int res = -1;
    for (int i = 0, j = 0; i < n; i++) {
        s[arr[i]]++;
        while (j < i && s[arr[i]] > 1) {
            s[arr[j]]--;
            j++;
        }
        res = max(res, i - j + 1);
    }
    cout << res << endl;
    return 0;
}
//10
//9 3 6 9 5 10 1 2 3 9