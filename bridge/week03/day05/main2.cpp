//
// Created by DELL on 2023/3/1.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e6 + 10;
#define pii pair<int,int>
struct edge {
    int u, v, w, nxt;
};
int n, m;
int head[N];
int vis[N];
int tot = 0;
edge edges[4 * N];
int dis[N];

void init() {
    memset(head, -1, (n + 1) * 4);
    memset(vis, 0, (n + 1) * 4);
    memset(dis, 0x7f, (n + 1) * 4);
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];

    head[u] = tot;
    tot++;
}

int dij(int u) {
    memset(vis, 0, (n + 1) * 4);
    memset(dis, 0x7f, (n + 1) * 4);
    dis[u] = 0;
    priority_queue<pair<int, int>, vector<pii >, greater<pair<int, int>>> q;
    q.push({0, u});
    while (!q.empty()) {
        pii node = q.top();
        q.pop();
        if (vis[node.second])continue;
        vis[node.second] = 1;
        int h = head[node.second];
        while (h != -1) {
            edge e = edges[h];
            if (dis[e.u] + e.w < dis[e.v]) {
                dis[e.v] = dis[e.u] + e.w;
                q.push({dis[e.v], e.v});
            }
            h = e.nxt;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
        addEdge(b, a, c);
    }
    int k;
    cin >> k;
    vector<int> shops;
    for (int i = 0; i < k; ++i) {
        int tp;
        cin >> tp;
        addEdge(0, tp, 0);
        addEdge(tp, 0, 0);
        shops.push_back(tp);
    }
    int q;
    cin >> q;
    dij(0);
    for (int i = 0; i < q; ++i) {
        int yk;
        cin >> yk;
        cout << dis[yk] << endl;
    }
    return 0;
}

