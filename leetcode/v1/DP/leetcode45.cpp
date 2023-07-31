//
// Created by DELL on 2023/3/23.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int jump(vector<int> &nums) {
        int n = nums.size();
        int dp[n + 1];
        memset(dp, 0x3f, sizeof dp);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= nums[i]; j++) {
                if (i + j >= n)break;
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
        return dp[n - 1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cout << 5 << endl;
    return 0;
}

