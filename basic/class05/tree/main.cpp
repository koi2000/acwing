#include "bits/stdc++.h"

#define ll long long
using namespace std;

const int N = 6010;

int n;

struct edge {
    int u, v, w, nxt;
};
edge edges[N];
int head[N];
int tot = 0;
int vis[N];
int dis[N];
int number[N];
int happy[N];
int f[N][2];
bool has_fa[N];

void init() {
    memset(head, -1, sizeof head);
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot++;
}

void dfs(int u) {
    f[u][1] = happy[u];
    int h = head[u];
    while (h != -1) {
        edge e = edges[h];
        dfs(e.v);
        f[u][1] += f[e.v][0];
        f[u][0] += max(f[e.v][0], f[e.v][1]);
        h = edges[h].nxt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    init();
    for (int i = 1; i <= n; ++i) {
        cin >> happy[i];
    }
    int l, k;
    for (int i = 0; i < n - 1; ++i) {
        cin >> l >> k;
        addEdge(k, l, 1);
        has_fa[l] = true;
    }
    int root = 1;
    while (has_fa[root])root++;
    dfs(root);
    cout << max(f[root][0], f[root][1]);
    return 0;
}
