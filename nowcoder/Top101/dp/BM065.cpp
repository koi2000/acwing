//
// Created by DELL on 2023/4/19.
//


#include <algorithm>
#include <cstring>
#include <vector>

class Solution {
public:
    /**
     * longest common subsequence
     * @param s1 string字符串 the string
     * @param s2 string字符串 the string
     * @return string字符串
     */
    string x = "";
    string y = "";

    string dfs(int i, int j, vector <vector<int>> &arr) {
        string res = "";
        if (i == 0 || j == 0) {
            return res;
        }
        if (arr[i][j] == 1) {
            res += dfs(i - 1, j - 1, arr);
            res += x[i - 1];
        } else if (arr[i][j] == 2) {
            res += dfs(i - 1, j, arr);
        } else if (arr[i][j] == 3) {
            res += dfs(i, j - 1, arr);
        }
        return res;
    }


    string LCS(string s1, string s2) {
        // write code here
        x = s1;
        int sz1 = s1.size();
        int sz2 = s2.size();
        int dp[sz1 + 1][sz2 + 1];
        int sz = min(sz1, sz2);
        vector <vector<int>> res(sz1 + 1, vector<int>(sz2 + 1));
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= sz1; i++) {
            for (int j = 1; j <= sz2; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    if (dp[i - 1][j - 1] + 1 > dp[i][j]) {
                        res[i][j] = 1;
                    }
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
                } else {
                    if (dp[i - 1][j] > dp[i][j - 1]) {
                        res[i][j] = 2;
                    } else {
                        res[i][j] = 3;
                    }
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[sz1][sz2] << endl;
        string ret = dfs(sz1, sz2, res);
        return ret != "" ? ret : "-1";
    }
};