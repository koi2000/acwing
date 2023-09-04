#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int maxn = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int sum[n + 1];
    memset(sum, 0, sizeof sum);
    for (int i = 1; i <= n; ++i) {
        int tp;
        cin >> tp;
        sum[i] = sum[i - 1] + tp;
    }
    if(sum[n]%3!=0) {
        cout<<0<<endl;
    }else {
        ll cnt = 0,res = 0;
        for (int i = 2; i < n; ++i) {
            if(sum[i-1]==sum[n]/3)cnt++;
            if(sum[i]==sum[n]/3*2)res+=cnt;
        }
        cout << res << endl;
    }
    return 0;
}
