//
// Created by DELL on 2023/1/11.
//

#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int maxn = 1e6 + 6;
struct edge {
    ll u, v, w, nxt;
};

ll tot = 0;

ll inf = 0x3f3f3f3f;
ll head[maxn];
ll dis[maxn];
ll vis[maxn];
edge edges[4 * maxn];
int n, m;

struct sign {
    ll pos;
    ll dis;

    sign(ll pos, ll dis) : pos(pos), dis(dis) {}

    bool operator<(const sign &rhs) const {
        return dis > rhs.dis;
    }

    bool operator>(const sign &rhs) const {
        return dis < rhs.dis;
    }
};

void init() {
    memset(head, -1, sizeof head);
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f3f3f3f, sizeof dis);
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;

    edges[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

void dij(int u) {
    priority_queue<sign> q;
    q.push({u, 0});
    dis[u] = 0;
    while (!q.empty()) {
        sign s = q.top();
        q.pop();
        if (vis[s.pos]) {
            continue;
        }
        vis[s.pos] = 1;
        ll h = head[s.pos];
        while (h != -1) {
            if (dis[edges[h].u] + edges[h].w <= dis[edges[h].v]) {
                dis[edges[h].v] = dis[edges[h].u] + edges[h].w;
                if (!vis[edges[h].v]) {
                    q.push({edges[h].v, dis[edges[h].v]});
                }
            }
            h = edges[h].nxt;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    init();
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        addEdge(x, y, z);
    }
    dij(1);
    if ((int) dis[n] == (int) 0x3f3f3f3f) {
        cout << -1 << endl;
    } else {
        cout << dis[n];
    }
    return 0;
}