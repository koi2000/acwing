//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n, N;
    cin >> n >> N;
    ll r = N / (n + 1);
    vector<ll> d(n + 1);
    d[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }
    ll p = 0;
    vector<pair<ll, ll>> flr;
    for (int i = 1; i <= n; ++i) {
        flr.emplace_back(d[i - 1], d[i] - 1);
    }
    flr.emplace_back(d.back(), N - 1);
    ll res = 0;
    for (int i = 0; i < N; i += r) {
        ll gl = i, gr = min(i + r - 1, N - 1);
        ll fl = flr[p].first, fr = flr[p].second;
        int rl = max(gl, fl);
        int rr = min(gr, fr);
        res += (rr - rl + 1) * abs(p - i / r);
        if (rr == fr) {
            p++;
        }
        if (rr != gr) {
            i -= r;
        }
    }
    cout << res << endl;
    return 0;
}