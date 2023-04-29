//
// Created by DELL on 2023/4/29.
//
class Solution {
public:
    string LCS(string str1, string str2) {
        //dp[i][j]表示到str1第i个个到str2第j个为止的公共子串长度
        vector <vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));
        int max = 0;
        int pos = 0;
        for (int i = 1; i <= str1.length(); i++) {
            for (int j = 1; j <= str2.length(); j++) {
                //如果该两位相同
                if (str1[i - 1] == str2[j - 1]) {
                    //则增加长度
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    //该位置为0
                    dp[i][j] = 0;
                }
                //更新最大长度
                if (dp[i][j] > max) {
                    max = dp[i][j];
                    pos = i - 1;
                }
            }
        }
        return str1.substr(pos - max + 1, max);
    }
};

