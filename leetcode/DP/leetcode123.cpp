leetcode121.cpp#include<bits / stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        int dp1[n + 1];
        int dp2[n + 1];
        memset(dp1, 0, sizeof dp1);
        memset(dp2, 0, sizeof dp2);
        int pro = 0;
        int price = INT_MAX;
        for (int i = 0; i < n; i++) {
            pro = max(pro, prices[i] - price);
            price = min(price, prices[i]);
            dp1[i] = pro;
        }
        pro = 0;
        price = -0x3f;
        for (int i = n - 1; i >= 0; i--) {
            pro = max(pro, price - prices[i]);
            price = max(price, prices[i]);
            dp2[i] = pro;
        }
        int res = -1;
        for (int i = 0; i < n; i++) {
            res = max(dp1[i] + dp2[i], res);
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cout << 5 << endl;
    return 0;
}

