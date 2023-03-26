#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int> &nums) {
        int n = nums.size();
        int dp[n + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = 1;
            }
        }
        return *max_element(dp, dp + n);
    }
};

int main() {
    return 0;
}

