#include<bits/stdc++.h>

#define ll long long
#define lowbit(x) (x&-x)
using namespace std;
const ll N = 31;
int arr[N];

int main() {
    int n, x;
    cin >> n >> x;
    int sum[n + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    // 不可能多出一件物品的价格
    int v = x + 10000;
    int dp[n + 1][v];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 0;
    // 模仿背包问题开始dp，v相当于背包容量
    for (int i = 1; i <= n; ++i) {
        for (int j = v; j >= 0; j--) {
            dp[i][j] = dp[i - 1][j];
            if (arr[i] <= j) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i]] + arr[i]);
            }
        }
    }
    int res = INT_MAX;
    for (int i = x; i < v; ++i) {
        if (dp[n][i] >= x) {
            res = min(res, dp[n][i]);
        }
    }
    cout << res << endl;
    return 0;
}