#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 2e5 + 10;

struct edge {
    int u, v, w, nxt;
};
int head[N];
int vis[N];
edge edges[4 * N];
int tot = 0;

void init() {
    memset(head, -1, sizeof head);
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

void dfs(int u) {
    if (vis[u])return;
    vis[u] = 1;
    int h = head[u];
    while (h != -1) {
        edge e = edges[h];
        if (!vis[e.v]) {
            dfs(e.v);
        }
        h = edges[h].nxt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    init();
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        addEdge(x, y, 1);
        addEdge(y, x, 1);
    }
    for (int i = 0; i < k; ++i) {
        int tp;
        cin >> tp;
        memset(vis, 0, sizeof vis);
        vis[tp] = 1;
        int count = 0;
        for (int j = 1; j <= n; ++j) {
            if (vis[j] == 0) {
                dfs(j);
                count++;
            }
        }
        cout << count - 1 << endl;
    }
    return 0;
}
