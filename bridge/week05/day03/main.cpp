#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
const int mod = 233333;

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
        b = b >> 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    cout << qpow(a, b);
    return 0;
}
