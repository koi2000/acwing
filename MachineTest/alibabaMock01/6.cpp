//
// Created by DELL on 2023/4/14.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 5110;
struct edge {
    int u, v, w, nxt;
};
int head[N];
edge edges[4 * N];
bool vis[N];

int dis[N];

int tot = 0;

int level[N];
map<int, set<int>> level2node;

void init() {
//    memset(vis,0,sizeof vis);
    memset(head, -1, sizeof head);
}

int n;

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

int distances[5010][5010];

void dij(int u) {
    priority_queue<pii > q;
    q.push({0, u});
    dis[u] = 0;
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
            h = edges[h].nxt;
        }
    }
}

int main() {
    //ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    cin >> n;
    init();
    for (int i = 1; i <= n; ++i) {
        cin >> level[i];
        level2node[level[i]].insert(i);
    }
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        addEdge(x, y, 1);
        addEdge(y, x, 1);
    }
    int res = 1061109567;
    for (int i = 1; i <= n; ++i) {
        memset(dis, 0x3f, sizeof dis);
        memset(vis, 0, sizeof vis);
        dij(i);
        set<int> levels = level2node[level[i]];
        for (int it:levels) {
            if (dis[it] != 0) {
                res = min(res, dis[it]);
            }
        }
    }
    res = res == 1061109567 ? -1 : res;
    cout << res << endl;
    return 0;
}

