/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include<bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int left = 0;
        for (int right = 0; right < n; right++) {
            if(nums[right]!=val){
                nums[left] = nums[right];
                left++;
            }
        }
        nums.resize(left);
        return left;
    }
};
// @lc code=end

