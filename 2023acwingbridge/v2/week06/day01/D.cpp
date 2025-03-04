//
// Created by DELL on 2023/9/4.
//
#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
    int n, v;
    cin >> n >> v;
    int dp[v + 1];
    memset(dp, 0, sizeof dp);
    vector<pii > g[n + 1];
    for (int i = 1; i <= n; ++i) {
        int s;
        cin >> s;
        for (int j = 0; j < s; ++j) {
            int x, y;
            cin >> x >> y;
            g[i].push_back({x, y});
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = v; j >= 0; --j) {
            for (int k = 0; k < g[i].size(); ++k) {
                if (j >= g[i][k].first) {
                    dp[j] = max(dp[j], dp[j - g[i][k].first] + g[i][k].second);
                }
            }
        }
    }
    cout << dp[v];

    return 0;
}

