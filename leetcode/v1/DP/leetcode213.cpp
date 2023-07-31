#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int robdp(vector<int> nums) {
        int n = nums.size();
        int dp[n + 1][2];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 0;
        dp[0][1] = nums[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }
        return max(dp[n - 1][0], dp[n - 1][1]);
    }

    int rob(vector<int> &nums) {
        int length = nums.size();
        if (length == 1) {
            return nums[0];
        } else if (length == 2) {
            return max(nums[0], nums[1]);
        }
        int res1 = robdp(vector(nums.begin(), nums.end() - 1));
        int res2 = robdp(vector(nums.begin() + 1, nums.end()));
        return max(res1, res2);
    }
};

int main() {
    return 0;
}

