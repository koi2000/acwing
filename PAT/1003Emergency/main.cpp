#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;

const int N = 2000;
struct edge {
    int u, v, w, nxt;
};
int n, m, c1, c2;
int head[N];
int number[N];
int tot = 0;
int vis[N];
edge edges[4 * N];
int dis[N];
int nums[N];
vector<vector<int>> pre;

void init() {
    memset(head, -1, (n + 1) * 4);
    memset(dis, 0x7f, (n + 1) * 4);
    memset(vis, 0, (n + 1) * 4);
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
    priority_queue<pii, vector<pii >, greater<pii>> q;
    q.push({0, u});
    dis[u] = 0;
    nums[u] = number[u];

    for (int i = 0; i < n; ++i) {
        if (dis[n] < 0x7f) {
            pre.push_back(vector<int>(1, u));
        } else {
            pre.push_back(vector<int>());
        }
    }
    while (!q.empty()) {
        pii nd = q.top();
        q.pop();
        int s = nd.second;
        if (vis[s])continue;
        vis[s] = 1;
        int h = head[s];
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

int dfs(int s, int e, int &paths, int sum) {
    if (s == e) {
        paths += 1;
        return sum;
    }
    int maxx = -1;
    for (int i = 0; i < pre[s].size(); ++i) {
        maxx = max(maxx, dfs(pre[s][i], e, paths, sum + number[pre[s][i]]));
    }
    return maxx;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> c1 >> c2;
    init();
    for (int i = 0; i < n; ++i) {
        cin >> number[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    dij(c1);
    int paths = 0;
    int res = number[c2] + dfs(c2, c1, paths, 0);
    cout << paths << " " << res << endl;
    return 0;
}
