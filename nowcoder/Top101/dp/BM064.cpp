#include <cmath>
#include <cstring>

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * @param cost int整型vector
     * @return int整型
     */
    int minCostClimbingStairs(vector<int> &cost) {
        // write code here
        int n = cost.size();
        int dp[n + 1];
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};