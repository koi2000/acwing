//
// Created by csp on 2023/3/19.
//
#include"bits/stdc++.h"

#define LL long long
#define pii pair<LL,LL>
using namespace std;
LL n, a, b;

LL area(LL x1, LL y1, LL x2, LL y2) {
    LL ll = max(x1, (LL) 0);
    LL bb = max(y1, (LL) 0);
    LL rr = min(x2, a);
    LL tt = min(y2, b);
    if (tt - bb <= 0 || rr - ll <= 0)return 0;
    LL re = max((tt - bb) * (rr - ll), (LL) 0);
    return re;
}

int main() {
    ios::sync_with_stdio(false);
    //cin.tie(0);
    //cout.tie(0);

    cin >> n >> a >> b;
    LL res = 0;
    for (LL i = 0; i < n; ++i) {
        LL x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        res += area(x1, y1, x2, y2);
    }
    cout << res << endl;
    return 0;
}
