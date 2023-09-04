#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N = 2e5 + 10;

int main() {
    ll n;
    cin >> n;
    ll arr[N + 1];
    ll sum[N + 1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i) {
        res+=(arr[i]*(sum[n]-sum[i]));
    }
    cout<<res<<endl;
    return 0;
}