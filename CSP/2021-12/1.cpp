//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
#define lowbit(x) (x & -x)
using namespace std;
const ll maxn = 1e8 + 9;
vector<ll> s(maxn);
ll n, N;
ll ask(ll p) {
    ll res = 0;
    for (ll i = p; i >= 1; i -= lowbit(i)) {
        res += s[i];
    }
    return res;
}

void upd(ll p, ll x) {
    for (ll i = p; i <= N; i += lowbit(i)) {
        s[i] += x;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> N;
    ll a[n + 1];
    a[0] = 0;
    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    // 区间更新，区间求和
    for (ll i = 1; i <= n; ++i) {
        upd(a[i], 1);
    }
    ll res = 0;
    int r = N / (n + 1);
    for (int i = 1; i < N; ++i) {
        res += (int) abs(ask(i) - i / r);
    }
    cout << res << endl;
    return 0;
}