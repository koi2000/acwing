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
    int n, l, r, k;
    cin >> n >> l >> r >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> g[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            g[i][j] += g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int x2 = i - r;
            int y2 = j - r;

            int x1 = i + r;
            int y1 = j + r;

            x2 = max(1, x2);
            y2 = max(1, y2);
            x1 = min(n, x1);
            y1 = min(n, y1);
            int num = (y1 - y2 + 1) * (x1 - x2 + 1);
            ll tp = g[x1][y1] - g[x2 - 1][y1] - g[x1][y2 - 1] + g[x2 - 1][y2 - 1];
            if (tp <= k * num) {
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}