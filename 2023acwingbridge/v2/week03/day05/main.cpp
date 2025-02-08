//
// Created by DELL on 2023/9/4.
//
#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 1e6 + 10;
int head[N];
int vis[N];
int dis[N];
int cnt[N];
struct edge {
    int u, v, w, nxt;
};

void dij(int i);

edge edges[4 * N];
int tot;
int n, m;

void init(int n = N) {
    memset(head, -1, 4 * (n + 1));
    memset(vis, 0, 4 * (n + 1));
    memset(cnt, 0, 4 * (n + 1));
    memset(dis, 0x3f3f3f, 4 * (n + 1));
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
    dis[u] = 0;
    q.push({u, 0});
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

void spfa(int u) {
    dis[u] = 0;
    cnt[u] = 1;
    queue<int> q;
    q.push(u);
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        int h = head[now];
        while (h != -1) {
            edge e = edges[h];
            if (dis[e.u] + e.w < dis[e.v]) {
                dis[e.v] = dis[e.u] + e.w;
                cnt[e.v] += 1;
                if (cnt[e.v] >= n) {
                    // 负环
                }
                vis[e.v] = 1;
                q.push(e.v);
            }
            h = e.nxt;
        }
        vis[now] = 0;
    }
}

int main() {

    cin >> n >> m;
    init(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    int k;
    cin >> k;
    vector<int> shops(k);
    for (int i = 0; i < k; ++i) {
        //cin>>shops[i];
        int tp;
        cin >> tp;
        addEdge(tp, 0, 0);
        addEdge(0, tp, 0);
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



