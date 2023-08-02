/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                     vector<int> &nums4) {
        unordered_map<int, int> countAB;
        for (int u : nums1) {
            for (int v : nums2) {
                ++countAB[u + v];
            }
        }
        int ans = 0;
        for (int u : nums3) {
            for (int v : nums4) {
                if (countAB.count(-u - v)) {
                    ans += countAB[-u - v];
                }
            }
        }
        return ans;
    }
};
// @lc code=end
