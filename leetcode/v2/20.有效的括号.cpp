/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if (s[i] == ')') {
                    if (!stk.empty()&&stk.top() == '(') {
                        stk.pop();
                    } else {
                        return false;
                    }
                }
                if (s[i] == ']') {
                    if (!stk.empty()&&stk.top() == '[') {
                        stk.pop();
                    } else {
                        return false;
                    }
                }
                if (s[i] == '}') {
                    if (!stk.empty()&&stk.top() == '{') {
                        stk.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        return stk.empty();
    }
};
// @lc code=end
