//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll g[4010][4010];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> g[i + j - 1][n - i + j];
        }
    }
    for (int i = 1; i <= n + m - 1; ++i) {
        for (int j = 1; j < n + m - 1; ++j) {
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    }
    ll res = INT_MIN;
    for (int i = r; i <= n - r + 1; ++i) {
        for (int j = r; j <= m - r + 1; ++j) {
            ll x1 = i + j + r - 2;
            ll y1 = n - i + j + r - 1;

            int x2 = i + j - r;
            int y2 = n - i + j - r + 1;

            res = max(res, g[x1][y1] - g[x2 - 1][y1] - g[x1][y2 - 1] + g[x2 - 1][y2 - 1]);
        }
    }
    cout << res << endl;
    return 0;
}