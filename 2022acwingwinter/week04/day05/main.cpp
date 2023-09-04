#include "bits/stdc++.h"

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        ll n, a, b;
        cin >> n >> a >> b;
        ll m = n - a * b + 2;
        ll l = 1, r = m >> 1;
        while (l < r) {
            ll mid = l + r >> 1;
            if (mid * (m - mid) >= n) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (l * (m - l) == n) {
            cout << l << " " << m - l << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
