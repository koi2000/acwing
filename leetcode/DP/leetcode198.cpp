#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        int dp[n + 1][2];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

int main() {
    int k;
    vector<int> prices;
    cin >> k;
    for (int i = 1; i <= 3; i++) {

        cin >> prices[1010];
    }
    int dp[110][1010];
    memset(dp, 0, sizeof(dp));
    int n = prices.size();
    for (int t = 1; t <= k; t++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                dp[t][i] = max(dp[t][i], dp[t - 1][j] + prices[i] - prices[j]);
            }
        }
    }
    int maxn = 0;
    for (int i = 1; i <= k; i++)
        maxn = max(maxn, dp[i][n]);
    cout << maxn;
    return 0;
}

