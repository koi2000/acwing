/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool isHappy(int n) {
        set<int> st;
        while (true) {
            if (n == 1)
                break;
            int num = n;
            n = 0;
            while (num) {
                n += ((num % 10) * (num % 10));
                num /= 10;
            }
            if (st.count(n)) return false;
            st.insert(n);
        }
        return true;
    }
};
// @lc code=end
