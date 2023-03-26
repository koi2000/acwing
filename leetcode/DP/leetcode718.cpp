#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int dp[n + 1][m + 1];
        memset(dp, 0, sizeof dp);
        int res = -1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
                res = max(res,dp[i][j]);
            }
        }
        return res;
    }
};

int main() {
    return 0;
}

