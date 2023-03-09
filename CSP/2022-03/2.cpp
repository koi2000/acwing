//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define lowbit(x) ( x & -x )
const ll MAXN = 1e6 + 1;
ll s[MAXN];

// 区间查询
ll ask(ll p) {
    ll res = 0;
    for (ll i = p; i >= 1; i -= lowbit(i)) {
        res += s[i];
    }
    return res;
}

//单点更新
void upd(ll p, ll x) {
    for (ll i = p; i <= MAXN; i += lowbit(i)) {
        s[i] += x;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int t, c;
    vector<int> timel;
    for (int i = 0; i < n; ++i) {
        cin >> t >> c;
        timel.push_back(t);
        if (t - c + 1 <= 0) {
            upd(1, 1);
        } else {
            upd(t - c + 1, 1);
        }

    }
    for (int i = 0; i < m; ++i) {
        int tp;
        cin >> tp;
        //int it = ask(tp + k);
        auto it = lower_bound(timel.begin(), timel.end(), tp + k);
        int lb = it - timel.begin();
        cout << ask(tp + k) - lb << endl;
    }
    return 0;
}