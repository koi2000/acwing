#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>

using namespace std;
const int N = 100000;
struct edge {
    int u, v, w, nxt;
};
edge edges[4 * N];
int head[N];
int tot = 0;
int vis[N];
int n, m;
int dis[N];
int number[N];

void init() {
    memset(head, -1, sizeof head);
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    tot = 0;
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot++;
}

void dij(int u) {
    priority_queue<pii, vector<pii >, greater<pii>> q;
    q.push({0, u});
    dis[u] = 0;

    while (!q.empty()) {
        pii nd = q.top();
        q.pop();
        if (vis[nd.second])continue;
        vis[nd.second] = 1;
        int h = head[nd.second];
        while (h != -1) {
            edge e = edges[h];
            if (dis[e.u] + e.w < dis[e.v]) {
                dis[e.v] = dis[e.u] + e.w;
                q.push({dis[e.v], e.v});
            }
            h = edges[h].nxt;
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    init();
    set<pii > path;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, 1);
        addEdge(v, u, 1);
        path.insert({u, v});
        path.insert({v, u});
    }
    dij(1);
    int res = dis[n];
    init();
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j && !path.count({i, j})) {
                addEdge(i, j, 1);
            }
        }
    }
    dij(1);
    res = max(res, dis[n]);
    if (res >= 1e6) {
        cout << -1 << endl;
    } else {
        cout << res << endl;
    }
    return 0;
}
