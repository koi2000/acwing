/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
    int jump(vector<int> &nums) {
        int size = nums.size();
        vector<int> dp(size + 1, INT_MAX-10000);
        dp[0] = 0;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j <= nums[i]; j++) {
                if (i + j >= size)
                    break;
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[size - 1];
    }
};
// @lc code=end
