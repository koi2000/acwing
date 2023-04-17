//
// Created by DELL on 2023/4/14.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    int k;
    cin >> k;
    int idx = 0;
    int weight[n - k];
    int val[n - k];
    //memset(val, 1, sizeof val);
    set<int> mark;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        weight[idx] = arr[x] + arr[y];
        val[idx] = 2;
        mark.insert(x);
        mark.insert(y);
        idx++;
    }
    for (int i = 0; i < n; ++i) {
        if (!mark.count(i)) {
            weight[idx] = arr[i];
            val[idx] = 1;
            idx++;
        }
    }
    int dp[n - k + 1][m + 1];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n - k; ++i) {
        for (int j = m; j >= 0; --j) {
            dp[i][j] = dp[i - 1][j];
            if (weight[i - 1] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i - 1]] + val[i - 1]);
            }
        }
    }
    cout << dp[n-k][m] << endl;
    return 0;
}

