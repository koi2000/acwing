//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define pii pair<int,int>
#define ll long long
using namespace std;

const int N = 100010;
struct edge {
    int u, v, w, nxt;
};
edge edges[N];
int head[N];
int tot = 0;
int vis[N];
int n, m;
int dis[N];
int times[N];
int in[N];

// 存储每个节点的前置节点，以及依赖前置节点的时间
map<int, pii > pre;

void init() {
    memset(head, -1, sizeof head);
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    memset(in, 0, sizeof in);
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot++;
}

void topsort() {
    queue<int> q;
    for (int i = 1; i <= m; ++i) {
        if (in[i] == 0) {
            q.push(i);
            pre[i] = {0, 0};
        }
    }
    while (!q.empty()) {
        int nd = q.front();
        q.pop();
        int h = head[nd];
        if (vis[nd])continue;
        vis[nd] = 1;
        while (h != -1) {
            edge e = edges[h];
            if (--in[e.v] == 0) {
                pre[e.v] = {e.u, times[e.u]};
                q.push(e.v);
            }
            h = edges[h].nxt;
        }
    }
}

int dfs(int s, int now) {
    if (s == 0)return now;
    dfs(pre[s].first, now + pre[s].second);
}

map<int, int> res;

int rdfs(int s, int now) {
    if (res.count(s)) {
        res[s] = max(res[s], now);
    } else {
        res[s] = now;
    }
    int h = head[s];
    edge e = edges[h];
    while (h != -1) {
        rdfs(e.v, now + times[e.v]);
        h = edges[h].nxt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    init();
    vector<int> deps(m + 1);
    for (int i = 1; i <= m; ++i) {
        int dep;
        cin >> dep;
        if (dep != 0) {
            addEdge(dep, i, 1);
            in[i]++;
        }
        deps[i] = dep;
    }
    for (int i = 1; i <= m; ++i) {
        int t;
        cin >> t;
        times[i] = t;
    }

    topsort();
    // 最早开始的时间
    for (int i = 1; i <= m; ++i) {
        cout << dfs(i, 0) + 1 << " ";
    }
    init();
    for (int i = 1; i <= m; ++i) {
        int dep = deps[i];
        if (dep != 0) {
            addEdge(i, dep, 1);
            in[dep]++;
        }
    }
    cout << endl;
    pre.clear();
//    topsort();

//    vector<int> res;
    bool flag = true;
    for (int i = 1; i <= m; ++i) {
        if (in[i] == 0) {
            rdfs(i, times[i]);
        }
    }
    for (auto &it:res) {
        if (n - it.second + 1 <= 0) {
            flag = false;
        } else {
            it.second = n - it.second + 1;
        }
    }
    if (flag && res.size() == m) {
        for (auto &it:res) {
            if (it.first) {
                cout << it.second << " ";
            }
        }
    }
    return 0;
}
