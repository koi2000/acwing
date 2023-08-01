/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<pair<int, int>> q;
        for (int i = 0; i < k - 1; i++) {
            while (!q.empty() && q.back().second < nums[i]) {
                q.pop_back();
            }
            q.push_back({i, nums[i]});
        }
        vector<int> res;
        for (int i = k - 1; i < nums.size(); i++) {
            while (!q.empty() && (i - q.front().first) >= k) {
                q.pop_front();
            }
            while (!q.empty() && q.back().second < nums[i]) {
                q.pop_back();
            }
            q.push_back({i, nums[i]});
            res.push_back(q.front().second);
        }
        return res;
    }
};
// @lc code=end
