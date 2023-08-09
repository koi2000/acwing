/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > k) return false;
            k = max(k, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end
