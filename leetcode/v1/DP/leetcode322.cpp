#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    vector<int> coin;
    int res = INT_MAX;
    map<int, int> mp;

    void dfs(int tar, int depth) {
        if (tar == 0) {
            res = min(res, depth);
        }
        if (tar < 0) return;
        for (int i = 0; i < coin.size(); i++) {
            if (coin[i] > tar)break;
            dfs(tar - coin[i], depth + 1);
        }
    }

    int coinChange(vector<int> &coins, int amount) {
        /*coin = coins;
        dfs(amount,0);
        return res==INT_MAX?-1:res;*/
        if (amount == 0)return 0;
        int n = coins.size();
        vector<int> dp(amount + 1, INT_MAX);
        for (int i = 0; i < n; i++) {
            if (coins[i] <= amount) {
                dp[coins[i]] = 1;
            }
        }
        for (int i = 0; i <= amount; i++) {
            cout << dp[i] << " ";
        }
        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= coins[j] && dp[i - coins[j]] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        if (dp[amount] == INT_MAX)return -1;
        return dp[amount];
    }
};

int main() {
    return 0;
}

