//
// Created by DELL on 2023/4/29.
//

#include <algorithm>
#include <cstring>

class Solution {
public:
    /**
     * 最少货币数
     * @param arr int整型vector the array
     * @param aim int整型 the target
     * @return int整型
     */
    int minMoney(vector<int> &arr, int aim) {
        // write code here
        if (aim == 0) {
            return 0;
        }
        int dp[aim + 1];
        memset(dp, 0x3f, sizeof(dp));
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= aim) {
                dp[arr[i]] = 1;
            }
        }
        for (int i = 1; i <= aim; i++) {
            for (int j = 0; j < arr.size(); j++) {
                if (i > arr[j]) {
                    dp[i] = min(dp[i], dp[i - arr[j]] + 1);
                }
            }
        }
        return dp[aim] > 100000 ? -1 : dp[aim];
    }
};
