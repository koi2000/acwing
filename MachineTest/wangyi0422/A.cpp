#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param price int整型vector 宝石价格列表
     * @param k int整型 行囊个数
     * @return int整型
     */
    vector<pair<int, int>> boundary;
    vector<int> prices;

    int getRes(vector<pair<int, int>> bdy) {
        int res = 0;
        for (int i = 0; i < bdy.size(); i++) {
            res += prices[bdy[i].first] + prices[bdy[i].second];
        }
        return res;
    }

    int n;
    int minres = INT_MAX;
    int maxres = -1;
    int mk;

    void dfs(int l, int k, int res) {
        if (k == 0 && l >= n) {
            minres = min(res, minres);
            maxres = max(res, maxres);
            return;
        }
        for (int len = 1; len <= n - k + 1 && l + len - 1 < n; len++) {
            int dl = prices[l];
            int dr = prices[l + len - 1];
            dfs(l + len, k - 1, res + dl + dr);
        }
    }

    int putGems(vector<int> &price, int k) {
        this->prices = price;
        //sort(arr.begin(),arr.end());
        this->n = price.size();
        this->mk = k;
        dfs(0, k, 0);
        return maxres - minres;
    }
};

int main() {
    ios::sync_with_stdio(false);
    Solution solution;
    int n, k;
    cin >> n >> k;
    vector<int> p;
    for (int i = 0; i < n; ++i) {
        int tp;
        cin >> tp;
        p.push_back(tp);
    }
    cout << solution.putGems(p, k);
    return 0;
}
