#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int dp[n+1];
        dp[0] = 0;
        dp[1] = cost[0];
        for(int i=2;i<=n;i++){
            dp[i] = min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        int dp2[n+1];
        dp2[0] = 0;
        dp2[1] = 0;
        dp2[2] = cost[1];
        for(int i=3;i<=n;i++){
            dp2[i] = min(dp2[i-1]+cost[i-1],dp2[i-2]+cost[i-2]);
        }
        return min(dp[n],dp2[n]);
    }
};

int main() {
    return 0;
}

