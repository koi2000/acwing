//
// Created by DELL on 2023/1/13.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;

const int N = 110, mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    unordered_map<int, int> primes;
    while (n--) {
        int x;
        cin >> x;
        for (int i = 2; i <= x / i; ++i) {
            while (x % i == 0) {
                x /= i;
                primes[i]++;
            }
        }
        if (x > 1)primes[x]++;
    }
    ll res = 1;
    for (auto item:primes) {
        res = res * (item.second + 1) % mod;
    }
    cout << res << endl;
    return 0;
}

