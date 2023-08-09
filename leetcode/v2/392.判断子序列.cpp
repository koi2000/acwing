/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class Solution {
  public:
    bool isSubsequence(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        if (slen > tlen)
            return false;
        int j = 0;
        for (int i = 0; i < tlen; i++) {
            if(t[i]==s[j]){
                j++;
            }
        }
        return j==slen;
    }
};
// @lc code=end
