/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = 0;
        int len = nums.size();
        int dp[len+1];
        memset(dp,0,sizeof dp);
        dp[0] = nums[0];
        for (int i = 1; i < len; i++) {
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
        }
        return *max_element(dp,dp+len);
    }
};
// @lc code=end

