//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
using namespace std;

ll n,a,b;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>a>>b;
    map<ll,ll>x;
    map<ll,ll>y;
    for (ll i = 0; i < a; ++i) {
        ll tx,ty;cin>>tx>>ty;
        x.insert({tx,ty});
    }
    for (ll i = 0; i < b; ++i) {
        ll tx,ty;cin>>tx>>ty;
        y.insert({tx,ty});
    }
    ll res = 0;
    for (auto it:x){
        if (y.count(it.first)){
            res+=it.second*y[it.first];
        }
    }
    cout<<res<<endl;
    return 0;
}
