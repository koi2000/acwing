#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;

const int N = 1010;
struct edge {
    int u, v, w, nxt;
};
edge edges[10* N];
int head[N];
int tot = 0;
int vis[N];
int n, m;
int dis[N];
int number[N];

vector<vector<int>> pre;
map<int, vector<int>> costs;

void init(int n) {
    tot = 0;
    memset(head, -1, (n + 1) * 4);
    memset(vis, 0, (n + 1) * 4);
    memset(dis, 0x3f, (n + 1) * 4);
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot++;
}

int spfa(int s, int t) {
    memset(vis, 0, (n + 1) * 4);
    memset(dis, 0x7f, (n + 1) * 4);
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    while (!q.empty()) {
        int hd = q.front();
        q.pop();
        int h = head[hd];
        while (h != -1) {
            edge e = edges[h];
            if (dis[e.u] + e.w < dis[e.v]) {
                dis[e.v] = dis[e.u] + e.w;
                if (!vis[e.v]) {
                    vis[e.v] = 1;
                    q.push(e.v);
                }
            }
            h = edges[h].nxt;
        }
        vis[hd] = 0;
    }
    return dis[t];
}


int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        init(n);
        for (int i = 1; i <= n; ++i) {
            int x, y;
            cin >> x >> y;
            if (x != -1) {
                addEdge(i, x, 1);
                addEdge(x, i, 1);
            }
            if (y != -1) {
                addEdge(i, y, 1);
                addEdge(y, i, 1);
            }
        }
        for (int i = 0; i < m; ++i) {
            int s, t;
            cin >> s >> t;
            cout << spfa(s, t) << endl;
        }

    }
    return 0;
}
