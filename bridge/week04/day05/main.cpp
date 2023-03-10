#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;

const int N = 1010;
struct edge {
    int u, v, w, nxt;
};
edge edges[10 * N];
int head[N];
int tot = 0;
int vis[N];
int n, m;
int dis[N];
int match[N];

void init(int size = N) {
    tot = 0;
    memset(head, -1, (size + 1) * 4);
    memset(vis, 0, (size + 1) * 4);
    memset(dis, 0x3f, (size + 1) * 4);
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot++;
}

// 匈牙利算法
// 为一个人找他的搭档，如果可匹配的搭档被占用了，就尝试让对方退出
// 如果对方不退出，就找自己下一个可能的搭档
int find(int u) {
    for (int h = head[u]; h != -1; h = edges[h].nxt) {
        edge e = edges[h];
        int v = e.v;
        if (!vis[v]) {
            vis[v] = 1;
            if (match[v] == 0 || find(match[v])) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}


int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    init(n);
    for (int i = 1; i <= n; ++i) {
        int num;
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int x;
            cin >> x;
            addEdge(i, x, 1);
            //addEdge(x,i,1);
        }
    }
    int res = 0;
    for (int i = 1; i <= m; ++i) {
        memset(vis, 0, sizeof vis);
        if (find(i))res++;
    }
    cout << res << endl;
    return 0;
}
