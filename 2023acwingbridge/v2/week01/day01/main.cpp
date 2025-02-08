//
// Created by DELL on 2023/9/4.
//
#include "bits/stdc++.h"

#define ll long long
#define pii pair<ll,ll>
using namespace std;

int main() {
    ll n;
    cin >> n;
    vector<ll> arr(n + 1, 0);
    for (ll i = 1; i <= n; ++i) {
        cin >> arr[i];
        arr[i] += arr[i - 1];
    }
    if (arr[n] % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }
    ll cnt = 0;
    ll res = 0;
    for (ll i = 1; i < n - 1; ++i) {
        if (arr[i] == arr[n] / 3) {
            cnt++;
        }
        if (arr[i + 1] == arr[n] * 2 / 3) {
            res += cnt;
        }
    }
    cout << res << endl;
    return 0;
}

