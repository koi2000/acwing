#include<bits/stdc++.h>

#define ll long long
#define pii pair<ll,ll>
using namespace std;
ll n, m, s;
ll arr[10010];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> s;
    for (ll i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ll l = 0, r = 0;
    pii bucket = {arr[0], arr[0]};
    ll res = 0;
//    for (ll i = 1; i < n; ++i) {
//        // 选择旧果篮
//        ll mn = min(bucket.first, arr[i]);
//        ll mx = max(bucket.second, arr[i]);
//        ll sum1 = (mx + mn) / 2 * (r - l + 2) + s;
//        // 新开果篮
//        ll sum2 = (bucket.second + bucket.first) / 2 * (r - l + 1) + s + arr[i] + s;
//        if (sum2 <= sum1) {
//            res += (bucket.second + bucket.first) / 2 * (r - l + 1) + s;
//            l = r = i;
//            bucket = {arr[i], arr[i]};
//        } else {
//            bucket = {mn, mx};
//            r = i;
//        }
//    }
    for (int i = 1; i < n; ++i) {
        ll mn = min(bucket.first, arr[i]);
        ll mx = max(bucket.second, arr[i]);
        if ((mx - mn)/2 >= s) {
            res += (bucket.second + bucket.first) / 2 * (r - l + 1) + s;
            l = r = i;
            bucket = {arr[i], arr[i]};
        } else {
            bucket = {mn, mx};
            r = i;
        }
    }
    res += (bucket.second + bucket.first) / 2 * (r - l + 1) + s;
    cout << res << endl;
    return 0;
}
