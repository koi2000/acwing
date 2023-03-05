#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 2e3 + 10;

vector<int> times;
set<int> start;
vector<vector<pii>> plans;

int d[N];   //作物的种植时间
int g[N];   //得到物种i需要的最短杂交时间
bool st[N];

int dfs(int tar) {
    if (st[tar])return g[tar];
    for (int i = 0; i < plans[tar].size(); ++i) {
        pii t = plans[tar][i];
        g[tar] = min(g[tar], max(times[t.first], times[t.second]) + max(dfs(t.first), dfs(t.second)));
    }
    st[tar] = true;
    return g[tar];
}


int main() {
    ios::sync_with_stdio(false);
    int n, m, k, t;
    cin >> n >> m >> k >> t;
    memset(g, 0x3f, sizeof g);
    times.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        int tm;
        cin >> tm;
        times[i] = tm;
    }
    for (int i = 0; i < m; ++i) {
        int tp;
        cin >> tp;
        start.insert(tp);
        g[tp] = 0;
        st[tp] = true;
    }
    plans.resize(N,vector<pii>());
    for (int i = 0; i < k; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        plans[c].push_back({a, b});
    }
    cout << dfs(t);
    return 0;
}
