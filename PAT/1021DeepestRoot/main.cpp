#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;

const int N = 100010;
struct edge {
    int u, v, w, nxt;
};
edge edges[N];
int head[N];
int tot = 0;
int vis[N];
int cm, n, sp, m;
int dis[N];
int number[N];

vector<vector<int>> pre;

void init() {
    memset(head, -1, sizeof head);
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
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
    q.push({0, u});
    dis[u] = 0;
    for (int i = 0; i <= n; ++i) {
        pre.push_back(vector<int>());
    }

    while (!q.empty()) {
        pii nd = q.top();
        q.pop();
        if (vis[nd.second])continue;
        vis[nd.second] = 1;
        int h = head[nd.second];
        while (h != -1) {
            edge e = edges[h];
            if (dis[e.u] + e.w < dis[e.v]) {
                dis[e.v] = dis[e.u] + e.w;
                pre[e.v].clear();
                pre[e.v].push_back(e.u);
                q.push({dis[e.v], e.v});
            } else if (dis[e.u] + e.w == dis[e.v]) {
                pre[e.v].push_back(e.u);
            }
            h = edges[h].nxt;
        }
    }
}

void dfs(int u) {
    if (vis[u]) return;
    vis[u] = 1;
    int h = head[u];
    while (h != -1) {
        dfs(edges[h].v);
        h = edges[h].nxt;
    }
}

//map<int, vector<int>> order;

int bfs(int u) {
    queue<pii > q;
    memset(vis, 0, (n + 1) * 4);
    q.push({0, u});
    int maxx = -1;
    while (!q.empty()) {
        pii hd = q.front();
        q.pop();
        int h = head[hd.second];
        if (vis[hd.second])continue;
        vis[hd.second] = 1;
        while (h != -1) {
            q.push({hd.first + 1, edges[h].v});
            maxx = max(maxx, hd.first + 1);
            h = edges[h].nxt;
        }
    }
    return maxx;
}

int main() {
//    ios::sync_with_stdio(false);
    cin >> n;
    init();
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v, 1);
        addEdge(v, u, 1);
    }
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
            count++;
        }
    }
    if (count > 1) {
        printf("Error: %d components", count);
        return 0;
    }
    map<int, vector<int>> res;
    for (int i = 1; i <= n; ++i) {
        int rt = bfs(i);
        if (res.count(rt)) {
            res[rt].push_back(i);
        } else {
            res[rt] = vector<int>(1, i);
        }
    }
    auto out = res.rbegin()->second;
    sort(out.begin(), out.end());
    for (int i = 0; i < out.size(); ++i) {
        cout << out[i] << endl;
    }
    return 0;
}
