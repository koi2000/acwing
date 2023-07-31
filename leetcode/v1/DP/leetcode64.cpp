//
// Created by DELL on 2023/3/23.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n][m];
        memset(dp, 0, sizeof dp);
        dp[0][0] = grid[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)continue;
                int res = INT_MAX;
                if (i - 1 >= 0) {
                    res = min(res, dp[i - 1][j]);
                }
                if (j - 1 >= 0) {
                    res = min(res, dp[i][j - 1]);
                }
                dp[i][j] = res + grid[i][j];
            }
        }
        return dp[n - 1][m - 1];
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

