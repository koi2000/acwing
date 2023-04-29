//
// Created by DELL on 2023/4/29.
//
#include <algorithm>
#include <cstring>
class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int n = array.size();
        int dp[n + 1];
        memset(dp, -0x3f, sizeof(dp));
        for (int i = 1; i <= n; i++) {
            dp[i] = max(array[i - 1], dp[i - 1] + array[i - 1]);
        }
        return *max_element(dp, dp + n + 1);
    }
};
