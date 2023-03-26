#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pro = 0;
        int price = INT_MAX;
        for(int i=0;i<prices.size();i++){
            pro = max(pro,prices[i]-price);
            price = min(price,prices[i]);
        }
        return pro;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cout << 5 << endl;
    return 0;
}

