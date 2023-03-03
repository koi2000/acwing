//
// Created by DELL on 2023/3/1.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e6 + 10;

int n, l;
struct edge {
    int u, v, w, nxt;
};
int head[N], vis[N];
edge edges[N * 4];
int tot = 0;

struct node {
    int idx;
    int level;

    node() {}

    node(int idx, int level) : idx(idx), level(level) {}
};

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

int bfs(int u) {
    queue<node> q;
    memset(vis, 0, sizeof vis);
    q.push({u, 0});
    vis[u] = 1;
    int cnt = 0;
    while (!q.empty()) {
        node hd = q.front();
        q.pop();
        int h = head[hd.idx];
        if (hd.level > l) {
            continue;
        }
        while (h != -1) {
            int v = edges[h].v;
            if (hd.level < l && !vis[v]) {
                cnt++;
                vis[v] = 1;
                q.push({v, hd.level + 1});
            }
            h = edges[h].nxt;
        }
    }
    return max(cnt, 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> l;
    init();
    for (int i = 1; i <= n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int tp;
            cin >> tp;
            addEdge(tp, i, 1);
        }
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i) {
        int p;
        cin >> p;
        cout << bfs(p) << endl;
    }
    return 0;
}

