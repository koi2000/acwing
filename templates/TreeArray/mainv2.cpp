#include<bits/stdc++.h>

using namespace std;
#define int long long
const int maxn = 1e6 + 5;
int n, q, a[maxn], maxx, b[maxn], c[maxn];

inline int lowbit(int a) {
    return a & (-a);
}

inline void update(int x, int y) {
    for (int i = x; i <= n; i += lowbit(i)) {
        b[i] += y;
        c[i] += x * y;
    }
}

inline void range_update(int l, int r, int x) {
    update(l, x);
    update(r + 1, -x);
}

inline int query(int x) {
    int ans = 0;
    for (int i = x; i; i -= lowbit(i)) {
        ans += (x + 1) * b[i] - c[i];
    }
    return ans;
}

inline int range_query(int l, int r) {
    return query(r) - query(l - 1);
}

signed main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        update(i, a[i] - a[i - 1]);
    }
    for (int i = 1; i <= q; i++) {
        int abc, x, y, z;
        cin >> abc;
        if (abc == 1) {
            cin >> x >> y >> z;
            range_update(x, y, z);
        } else {
            cin >> x >> y;
            cout << range_query(x, y) << endl;
        }
    }
    return 0;
}
