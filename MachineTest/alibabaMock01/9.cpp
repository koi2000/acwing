#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int n, m, a;
ll ans = 0;
vector<int> v[400005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int i, j = 1, best = 0;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
        cin >> a;
        v[a].push_back(i);
        if (v[a].size() == m) {
            best = max(best, v[a][0]);
            v[a].erase(v[a].begin());
        }
        ans += best;
    }
    cout << ans;
    return 0;
}