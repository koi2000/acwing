//
// Created by DELL on 2023/4/14.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<ll,ll>
using namespace std;
ll mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    // dp[i][j]表示i个节点能组成的高度不超过j的树的个数
    ll dp[n + 1][m + 1];
    memset(dp, 0, sizeof dp);
    for (ll i = 0; i <= m; ++i) {
        dp[0][i] = 1;
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= m; ++j) {
            for (ll k = 0; k < i; ++k) {
                dp[i][j] = (dp[i][j] + dp[k][j - 1] * dp[i - k - 1][j - 1] % mod) % mod;
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}

