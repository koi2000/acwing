//
// Created by DELL on 2023/1/11.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;

const int maxn = 1e6 + 10;
struct edge {
    int u, v, w, nxt;
};

ll tot = 0;
ll head[maxn];
ll dis[maxn];
ll vis[maxn];
ll cnt[maxn];
edge edges[4 * maxn];

struct sign {
    ll pos;
    ll dis;

    sign(long long int pos, long long int dis) : pos(pos), dis(dis) {}

    bool operator<(const sign &rhs) const {
        return dis < rhs.dis;
    }

    bool operator>(const sign &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const sign &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const sign &rhs) const {
        return !(*this < rhs);
    }
};

void init() {
    tot = 0;
    memset(head, -1, sizeof head);
    memset(dis, -1, sizeof dis);
    memset(vis, -1, sizeof vis);
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
    ios::sync_with_stdio(false);
    init();

    return 0;
}
