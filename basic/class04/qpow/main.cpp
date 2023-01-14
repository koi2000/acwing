//
// Created by DELL on 2023/1/13.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;

ll qpow(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1)res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << qpow(a, b, c) << endl;
    }

    return 0;
}

