#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int dp[110][1010];
        memset(dp, 0, sizeof(dp));
        int n = prices.size();
        for (int t = 1; t <= k; t++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    dp[t][i] = max(dp[t][i], dp[t - 1][j] + prices[i] - prices[j]);
                }
                if (i >= 1)
                    dp[t][i] = max(dp[t][i], dp[t][i - 1]);
            }
        }
        int maxn = 0;
        for (int i = 1; i <= k; i++)
            maxn = max(maxn, dp[i][n - 1]);
        return maxn;
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

