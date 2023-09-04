#include<bits/stdc++.h>

#define ll long long
#define lowbit(x) (x&-x)
using namespace std;
const ll N = 1e5 + 10;
ll n;
ll arr[N];
ll sum[N];
pair<ll, ll> asum[N + 1];
ll narr[N + 1];
ll nsum[N + 1];
vector<ll> diff(N + 2,0);
//ll ask(ll p) {
//    ll res = 0;
//    for (ll i = p; i >= 1; i -= lowbit(i)) {
//        res += s[i];
//    }
//    return res;
//}
//
//void upd(ll p, ll x) {
//    for (ll i = p; i <= n; i += lowbit(i)) {
//        s[i] += x;
//    }
//}

bool cmp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.first < b.first;
}

int main() {
    cin >> n;
    sum[0] = 0;
    for (ll i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
//    cout<<1<<endl;
    // memset(diff, 0, sizeof diff);
    ll m;
    cin >> m;
    ll res1 = 0;
    vector<ll> lll;
    vector<ll> rrr;
    for (ll i = 0; i < m; ++i) {
        ll l, r;
        cin >> l >> r;
        lll.push_back(l);
        rrr.push_back(r);
        diff[l] += 1;
        diff[r + 1] -= 1;
        res1 += (sum[r] - sum[l - 1]);
    }
    sum[0] = 0;

    for (ll i = 1; i <= n; ++i) {
        asum[i].first = asum[i - 1].first + diff[i];
        asum[i].second = i;
    }
    sort(asum + 1, asum + n + 1, cmp);
    sort(arr + 1, arr + 1 + n);

    for (ll i = 1; i <= n; ++i) {
        narr[asum[i].second] = arr[i];
    }

    nsum[0] = 0;
    for (ll i = 1; i <= n; ++i) {
        nsum[i] = nsum[i - 1] + narr[i];
    }
    ll nres = 0;
    for (ll i = 0; i < lll.size(); ++i) {
        ll l = lll[i];
        ll r = rrr[i];
        nres += (nsum[r] - nsum[l - 1]);
    }
    cout << nres - res1 << endl;
    return 0;
}