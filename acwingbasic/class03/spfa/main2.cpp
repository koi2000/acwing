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

bool spfa(int u) {
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        dis[i] = 0;
        q.push(i);
        vis[i] = 1;
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        vis[t] = false;
        int h = head[t];
        while (h != -1) {
            edge j = edges[h];
            if (dis[j.v] > dis[t] + j.w) {
                cnt[j.v] = cnt[j.u] + 1;
                dis[j.v] = dis[t] + j.w;
                if (cnt[j.v] >= n) {
                    return true;
                }
                if (!vis[j.v]) {
                    q.push(j.v);
                    vis[j.v] = true;
                }
            }
            h = j.nxt;
        }
    }
    return false;
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
    if (spfa(1)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}