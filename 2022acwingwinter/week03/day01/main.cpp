#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 10;
ll n, m;
ll a[N], b[N];
ll l = 0, r = 1e6;

ll topdiv(ll a, ll b) {
    if (a % b == 0) {
        return a / b;
    } else {
        return a / b + 1;
    }
}

bool check(int x) {
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > x) {
            res += topdiv(a[i] - x, b[i]);
        }
    }
    return res <= m;
}

int main() {

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
    }
    while (l < r) {
        ll mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    ll cnt = 0;
    ll ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] > l) {
            ll num = topdiv(a[i] - l, b[i]);
            ll tpl = a[i] - (num - 1) * b[i];
            cnt += num;
            ans += ((tpl + a[i]) * num / 2);
        }
    }
    cout << ans + l * (m - cnt);
    return 0;
}