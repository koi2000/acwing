#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
int n, x, y;

int gcd(int a, int b) {
    if (b) return gcd(b, a % b);
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> x >> y;
    map<pii, int> mp;
    for (int i = 0; i < n; ++i) {
        int tx, ty;
        cin >> tx >> ty;
        int ts = gcd(ty - y, tx - x);
        pii k = {(ty - y) / ts, (tx - x) / ts};
        if (mp.count(k))mp[k]++;
        else mp[k] = 1;
    }
    cout << mp.size() << endl;
    return 0;
}
