#include "bits/stdc++.h"

#define ll long long
using namespace std;

ll getMaxRadix(string str) {
    ll maxx = -1;
    for (ll i = 0; i < str.size(); ++i) {
        if (islower(str[i])) {
            maxx = max(maxx, (ll) (str[i] - 'a' + 10 + 1));
        } else {
            maxx = max(maxx, (ll) (str[i] - '0' + 1));
        }
    }
    return maxx;
}

ll changeRadix(string str, ll radix) {
    ll rdx = 1;
    ll sum = 0;
    for (ll i = str.size() - 1; i >= 0; --i) {
        ll rel = 0;
        if (islower(str[i])) {
            rel = str[i] - 'a' + 10;
        } else {
            rel = str[i] - '0';
        }
        sum += rel * rdx;
        rdx *= radix;
    }
    return sum;
}


signed main() {
    ios::sync_with_stdio(false);
    string n1, n2;
    ll tag, radix;
    cin >> n1 >> n2 >> tag >> radix;
    if (tag == 2) {
        swap(n1, n2);
    }
    ll num1 = changeRadix(n1, radix);
    ll l = getMaxRadix(n2) - 1, r = max(l, num1) + 2;
    ll ans = 0;
    while (r - l > 1) {
        ll mid = (l + r) >> 1;
        ll tp = changeRadix(n2, mid);
        if (tp < 0 || tp >= num1) {
            r = mid;
            ans = mid;
        } else {
            l = mid;
        }
    }
//    ll l = getMaxRadix(n2), r = max(l, num1) + 1;
//    ll ans = 0;
//    while (l <= r) {
//        ll mid = (l + r) >> 1;
//        ll tp = changeRadix(n2, mid);
//        if (tp < 0 || tp > num1) {
//            r = mid - 1;
//        } else if (tp < num1) {
//            l = mid + 1;
//        } else {
//            ans = mid;
//            break;
//        }
//    }
    ll tp = changeRadix(n2, ans);
    if (tp != num1) {
        cout << "Impossible";
    } else {
        cout << ans;
    }
    return 0;
}
