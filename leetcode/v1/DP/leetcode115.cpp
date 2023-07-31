//
// Created by DELL on 2023/3/23.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (n < m)return 0;
        unsigned long long dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; ++i) {
        int tp;
        cin >> tp;
        arr.push_back(tp);
    }
    Solution solution;
    solution.canJump(arr);
    return 0;
}

