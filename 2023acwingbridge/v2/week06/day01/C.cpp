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
    int va[n + 1], wa[n + 1];
    int dp[v + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        cin >> va[i] >> wa[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = va[i]; j <= v; ++j) {
//            dp[i][j] = dp[i - 1][j];
            dp[j] = max(dp[j], dp[j - va[i]] + wa[i]);
        }
    }
    cout << dp[v];
    return 0;
}

