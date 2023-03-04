#include "bits/stdc++.h"

#define ll long long
using namespace std;

int main() {
//    ios::sync_with_stdio(false);
    int n;
    map<int, double> mp;
    cin >> n;
    int a;
    double b;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        mp[a] = b;
    }
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b;
        if (mp.count(a)) {
            mp[a] += b;
        } else {
            mp[a] = b;
        }
    }
    for (auto it = mp.begin();it!=mp.end();) {
        if (fabs(it->second)<=1e-7){
            mp.erase(it++);
        }else{
            it++;
        }
    }
    cout << mp.size();
    for (auto i = mp.rbegin(); i != mp.rend(); ++i) {
        printf(" %d %.1f",i->first,i->second);
    }
    return 0;
}
