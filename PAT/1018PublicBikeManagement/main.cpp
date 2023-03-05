#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;

const int N = 1000;
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
map<int, vector<int>> costs;

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

void dfs(int s, int e, int sum, int need, vector<int> order) {
    if (s == e) {
        costs[sum] = order;
        return;
    }
    for (int i = 0; i < pre[s].size(); ++i) {
        order.push_back(pre[s][i]);
        dfs(pre[s][i], e, sum + max(number[pre[s][i]] - cm / 2, 0), need + number[pre[s][i]] - cm / 2, order);
        order.pop_back();
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin >> cm >> n >> sp >> m;
    init();
    for (int i = 1; i <= n; ++i) {
        cin >> number[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    dij(0);
    dfs(sp, 0, 0, vector<int>());
    vector<int> res;
    int send = 0;
    int back = 0;
    for (auto it:costs) {
        if (it.first < cm / 2) {
            send = cm / 2 - it.first;
            back = 0;
            res = it.second;
        } else if (it.first == cm / 2) {
            send = 0;
            back = 0;
            res = it.second;
            break;
        } else {
            send = 0;
            back = it.first - cm / 2;
            res = it.second;
            break;
        }
    }
    cout << send << " ";
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << "->";
    }
    cout << sp << " ";
    cout << back;
    return 0;
}
