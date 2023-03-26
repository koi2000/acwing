#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        int m = triangle[n - 1].size();

        int dp[n][m];
        memset(dp, 0x3f, sizeof dp);
        dp[0][0] = triangle[0][0];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < triangle[i].size(); j++) {
                if (i - 1 >= 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + triangle[i][j]);
                    if (j - 1 >= 0) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + triangle[i][j]);
                    }
                }
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < m; i++) {
            res = min(res, dp[n - 1][i]);
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cout << 5 << endl;
    return 0;
}

