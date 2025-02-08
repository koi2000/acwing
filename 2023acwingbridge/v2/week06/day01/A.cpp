//
// Created by DELL on 2023/9/4.
//
#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;
const int mod = 1e9;

int main() {
    int n;
    cin >> n;
    int dp[n];
    memset(dp, 0, sizeof dp);
    dp[0] = 1;
    for (int i = 1; i <= n; i *= 2) {
        for (int j = i; j <= n; ++j) {
            dp[j] = (dp[j] + dp[j - i]) % mod;
        }
    }
    cout << dp[n];
    return 0;
}

