//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    int arr[n + 1];
    int dp[n + 1][x + 10000];
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; ++i) {
        for (int v = x + 10000; v >= 0; --v) {
            dp[i][v] = dp[i - 1][v];
            if (v >= arr[i]) {
                dp[i][v] = max(dp[i][v], dp[i - 1][v - arr[i]] + arr[i]);
            }
        }
    }
    int res = INT_MAX;
    for (int i = x; i < x + 10000; ++i) {
        if (dp[n][i] >= x) {
            res = min(res, dp[n][i]);
        }
    }
    cout << res;
    return 0;
}
