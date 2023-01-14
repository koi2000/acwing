//
// Created by DELL on 2023/1/11.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int maxn = 1e6 + 6;

struct edge {
    int u, v, w, nxt;
};
int tot = 0;
int head[maxn];
int dis[maxn];
int vis[maxn];
int cnt[maxn];
int in[maxn];
edge edges[4 * maxn];
int n, m;

void init() {
    tot = 0;
    memset(in, 0, sizeof(in));
    memset(head, -1, sizeof(head));
    memset(cnt, 0, sizeof(cnt));
}

int spfa() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    queue<int> q;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        vis[t] = false;
        int h = head[t];
        while (h != -1) {
            edge j = edges[h];
            if (dis[j.v] > dis[t] + j.w) {
                dis[j.v] = dis[t] + j.w;
                if (!vis[j.v]) {
                    q.push(j.v);
                    vis[j.v] = true;
                }
            }
            h = j.nxt;
        }
    }
    return dis[n];
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        addEdge(a, b, c);
    }
    spfa();
    if (dis[n] == 0x3f3f3f3f) {
        cout << "impossible";
    } else {
        cout << dis[n];
    }
    return 0;
}