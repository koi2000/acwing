//
// Created by DELL on 2023/4/20.
//
#include <cstring>

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int rob(vector<int> &nums) {
        // write code here
        int n = nums.size();
        int dp1[n][2];
        memset(dp1, 0, sizeof dp1);
        dp1[0][0] = 0;
        dp1[0][1] = nums[0];

        int dp2[n][2];
        memset(dp2, 0, sizeof dp2);
        dp2[1][0] = 0;
        dp2[1][1] = nums[1];
        for (int i = 1; i < n - 1; i++) {
            dp1[i][0] = max(dp1[i - 1][1], dp1[i - 1][0]);
            dp1[i][1] = dp1[i - 1][0] + nums[i];
        }
        for (int i = 2; i < n; i++) {
            dp2[i][0] = max(dp2[i - 1][1], dp2[i - 1][0]);
            dp2[i][1] = dp2[i - 1][0] + nums[i];
        }
        return max(max(dp1[n - 2][0], dp1[n - 2][1]), max(dp2[n - 1][0], dp2[n - 1][1]));
    }
};
