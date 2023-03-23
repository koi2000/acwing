//
// Created by DELL on 2023/3/23.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1)return 1;
        if (n == 2)return 2;
        int dp[n + 1];
        memset(dp, 0, sizeof dp);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 2] + dp[i - 1];
        }
        return dp[n];
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

