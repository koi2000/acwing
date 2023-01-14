#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 2e5 + 10;
int diff[N];
int sum[N];

int main() {
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    set<pair<int, int>> st;

    memset(diff, 0, sizeof diff);
//    memset(diff, 0, sizeof diff);
    for (int i = 0; i < n; ++i) {
        int t, c;
        cin >> t >> c;
        int r = t - k;
        int l = t - c - k;
        if (l <= 0) {
            l = 1;
        } else {
            l++;
        }
        if (r >= l && r > 0) {
            diff[l] += 1;
            diff[r + 1] -= 1;
        }

    }
//    sum[0] = diff[0];
    for (int i = 1; i <= 2e5 + 2; ++i) {
        sum[i] = sum[i - 1] + diff[i];
    }
    for (int i = 0; i < m; ++i) {
        int q;
        cin >> q;
        cout << sum[q] << endl;
    }
    return 0;
}
