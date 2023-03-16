#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 2010;
const ll mod = 998244353;
ll dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    // 第i个位置有j种不同的方案

    for (int i = 1; i <= n; i++) {
        dp[1][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = m;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            dp[i][j] = (dp[i - 1][j] + (dp[i - 1][j - 1] * (m - 1))%mod)%mod;
        }
    }
    cout << dp[n][k];
    return 0;
}
