//
// Created by DELL on 2023/1/11.
//
#include "bits/stdc++.h"

using namespace std;

const int N = 510, INF = 0x3f3f3f3f, M = 1e5 + 10;
int n, m;
struct edge {
    int u, v, w, nxt;
};

int head[N];
edge edges[M];
int idx = 0;
int dis[N];
bool vis[N];

void addEdge(int u, int v, int w) {
    edges[idx].u = u;
    edges[idx].v = v;
    edges[idx].w = w;
    edges[idx].nxt = head[u];
    head[u] = idx;
    idx++;
}

//创建一个节点类，存储所有可到达节点的信息
class node {
public:
    int pos;
    int dis;

    node(int pos, int dis) : pos(pos), dis(dis) {}

    bool operator<(const node &a) const {
        return this->dis > a.dis;
    }
};

int prim() {
    set<int> nodes;
    nodes.insert(1);
    queue<int> q;
    q.push(1);
    int k = 0;
    int res = 0;
    priority_queue<node> qq;
    while (k < n - 1) {
        int x = q.front();
        q.pop();
        int h = head[x];
        while (h != -1) {
            edge e = edges[h];
            if (nodes.count(e.v)) {
                h = edges[h].nxt;
                continue;
            } else {
                qq.push({e.v, e.w});
            }
            h = edges[h].nxt;
        }
        while (!qq.empty()){
            node tt = qq.top();
            int a = fin
        }
    }
}

int prims() {
    memset(dis, 0x3f, sizeof dis);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 1; j <= n; ++j) {
            if (!vis[j] && (t == -1 || dis[t] > dis[j])) {
                t = j;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    memset(head, -1, sizeof head);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;

    }
    int t = prim();
    if (t == INF) {
        cout << "impossible" << endl;
    } else {
        cout << t << endl;
    }
}

