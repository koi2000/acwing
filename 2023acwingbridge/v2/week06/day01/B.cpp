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
    int dp[n][v + 1];
    int wa[n + 1];
    int va[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> va[i] >> wa[i];
    }
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        for (int j = v; j >= 0; --j) {
            dp[i][j] = dp[i - 1][j];
            if (j >= va[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - va[i]] + wa[i]);
            }
        }
    }
    cout << dp[n - 1][v];
    return 0;
}

