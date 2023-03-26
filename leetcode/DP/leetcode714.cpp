#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices, int fee) {
        int n = prices.size();
        int dp[n + 1][2];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }
};

int main() {
    return 0;
}

