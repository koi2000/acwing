//
// Created by DELL on 2023/3/23.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int dp[n + 1];
        memset(dp, -0x3f, sizeof dp);
        for (int i = 0; i < n; i++) {
            dp[i + 1] = max(dp[i] + nums[i], nums[i]);
        }
        return *max_element(dp, dp + n + 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cout << 5 << endl;
    return 0;
}

