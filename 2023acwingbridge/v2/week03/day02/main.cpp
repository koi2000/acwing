//
// Created by DELL on 2023/9/4.
//
#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 1e6 + 10;
struct edge {
    int u, v, w, nxt;
};
int head[N];
int vis[N];
int tot = 0;
edge edges[4 * N];

void init(int n = N) {
    memset(head, -1, sizeof vis);
    memset(vis, 0, sizeof vis);
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot++;
}

int n, l;

void bfs(int u) {
    queue<pii > q;
    q.push({u, 0});
    int cnt = 0;
    memset(vis, 0, sizeof vis);
    while (!q.empty()) {
        pii tp = q.front();
        q.pop();
        if (tp.second > l)continue;
        if (vis[tp.first])continue;
        cnt++;
        vis[tp.first] = 1;
        int h = head[tp.first];
        while (h != -1) {
            edge e = edges[h];
            q.push({e.v, tp.second + 1});
            h = e.nxt;
        }
    }
    cout << cnt-1 << endl;
}

int main() {
    cin >> n >> l;
    init(n);
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int y;
            cin >> y;
            addEdge(y, i, 1);
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int q;
        cin >> q;
        bfs(q);
    }
    return 0;
}

