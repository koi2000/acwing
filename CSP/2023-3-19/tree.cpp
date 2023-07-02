//
// Created by DELL on 2023/3/19.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 1e6 + 10;
struct edge {
    int u, v, w, nxt;
};

edge edges[4 * N];
int head[N];
int dis[N];
int vis[N];
int cnt[N];
int tot = 0;

void init(int n = N) {
    memset(head, -1, (n + 1) * 4);
    memset(vis, 0, (n + 1) * 4);
    memset(dis, 0x3f, (n + 1) * 4);
}


void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    tot++;
}

void spfa(int u) {
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    dis[u] = 0;
    cnt[u] = 1;
    while (!q.empty()) {
        int hd = q.front();
        q.pop();
        vis[hd] = 0;
        int h = head[hd];
        while (h != -1) {
            edge e = edges[h];
            if (dis[e.v] > dis[e.u] + e.w) {
                dis[e.v] = dis[e.u] + e.w;
                if (!vis[e.v]) {
                    q.push(e.v);
                    vis[e.v] = 1;
                    cnt[e.v]++;
                    if (cnt[e.v] > n) {

                    }
                }
            }

            h = edges[h].nxt;
        }
    }
}

void dijkras(int u) {
    priority_queue<pii > q;
    q.push({0, u});
    dis[u] = 0;
    while (!q.empty()) {
        pii hd = q.top();
        q.pop();
        if (vis[hd.second])continue;
        vis[hd.second] = 1;
        int h = head[hd.second];
        while (h != -1) {
            edge e = edges[h];
            if (dis[e.v] > dis[e.u] + e.w) {
                dis[e.v] = dis[e.u] + e.w;
                q.push({dis[e.v], e.v});
            }
            h = edges[h].nxt;
        }
    }
}




int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    init(n);

    return 0;
}

