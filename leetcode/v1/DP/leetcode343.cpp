#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        int dp[n + 1];
        memset(dp, 0, sizeof dp);
        for (int i = 2; i <= n; i++) {
            int maxx = -1;
            for (int j = 1; j < i; j++) {
                maxx = max(maxx, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = maxx;
        }
        return dp[n];
    }
};

int main() {
    return 0;
}

