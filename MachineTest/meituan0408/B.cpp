#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 200010;
struct edge {
    int u, v, w, nxt;
};
int head[N];
edge edges[4 * N];
int tot = 0;
bool vis[N];

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

void init() {
    memset(head, -1, sizeof head);
}

int res = 0;

void dfs(int x, int y, int depth) {
    if (vis[x]) {
        res = max(res, depth - 1);
        return;
    }
    int h = head[x];
    vis[x] = true;
    while (h != -1) {
        edge e = edges[h];
        if (e.v != y) {
            dfs(e.v, y, depth + 1);
        }
        h = e.nxt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    init();
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        int x;
        cin >> x;
        addEdge(i + 1, x, 1);
        addEdge(x, i + 1, 1);
    }
    int x, y;
    cin >> x >> y;
    dfs(x, y, 0);
    int res1 = res;
    memset(vis, 0, sizeof vis);
    res = 0;
    dfs(y, x, 0);
    int res2 = res;
    cout << res1 + res2 + 1 << endl;
    return 0;
}
