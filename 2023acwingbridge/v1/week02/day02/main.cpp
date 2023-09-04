#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int maxn = 1e6 + 10;
int f[maxn];

int find(int x) {
    if (x == f[x]) return x;

    f[x] = find(f[x]);
    return f[x];
}

void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx != fy) {
        f[fx] = fy;
    }
}

void init() {
    for (int i = 0; i < maxn; ++i) {
        f[i] = i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, q;
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        f[i] = i;
    }
//    init();
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        f[find(x)] = find(y);
//        merge(x, y);
    }
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y;
        cin >> x >> y;
        if (find(x) == find(y)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
