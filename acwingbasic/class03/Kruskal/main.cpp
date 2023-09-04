//
// Created by DELL on 2023/1/11.
//
#include "bits/stdc++.h"

using namespace std;
const int N = 1e5 + 10, M = 2 * N;
const int maxn = 1e5 + 10;
int f[N];
int head[N];
int tot;

struct edge {
    int u, v, w, nxt;

    bool operator<(const edge &rhs) const {
        return w < rhs.w;
    }

    bool operator>(const edge &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const edge &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const edge &rhs) const {
        return !(*this < rhs);
    }
} edges[M];


int n, m;

//int find(int x) {
//    if (x == f[x])return x;
//    f[x] = find(f[x]);
//    return f[x];
//}

int find(int x)
{
    if (f[x] != x) f[x] = find(f[x]);
    return f[x];
}

void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    f[fx] = fy;
}

void init() {
    tot = 0;
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

void kurl() {
    sort(edges, edges + m);
    for (int i = 1; i <= n; i ++ ) f[i] = i;
    int sum = 0;
    int num = 0;
    for (int i = 0; i < m; ++i) {
        int a = edges[i].u, b = edges[i].v, w = edges[i].w;

        a = find(a), b = find(b);
        if (a != b)
        {
            f[a] = b;
            sum += w;
            num ++ ;
        }
    }
    if (num < n - 1) {
        cout << "impossible" << endl;
    } else {
        cout << sum << endl;
    }
}

int main() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
//        addEdge(v, u, w);
    }
    kurl();
    return 0;
}
