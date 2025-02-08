//
// Created by DELL on 2025/1/29.
//
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
struct edge {
  int u, v, w, nxt;
};

int tot = 0;
int head[N];
int dis[N];
int vis[N];
edge edges[N];

void init() {
  memset(vis, 0, sizeof vis);
  memset(dis, 0x3f, sizeof dis);
  memset(head, -1, sizeof head);
  tot = 0;
}

void addEdge(int u, int v, int w) {
  edges[tot].u = u;
  edges[tot].v = v;
  edges[tot].w = w;
  edges[tot].nxt = head[u];
  head[u] = tot++;
}

void dij(int s, int e) {
  priority_queue<pair<int, int>, std::vector<pair<int, int>>,
      greater<pair<int, int>>>
      q;
  q.push({0, s});
  dis[s] = 0;
  while (!q.empty()) {
    auto node = q.top();
    q.pop();
    if (vis[node.second]) {
      continue;
    }
    vis[node.second] = 1;
    int h = head[node.second];

    while (h != -1) {
      edge eg = edges[h];
      if (dis[edges[h].u] + edges[h].w <= dis[edges[h].v]) {
        dis[edges[h].v] = dis[edges[h].u] + edges[h].w;
        if (!vis[edges[h].v]) {
          q.push({dis[edges[h].v], edges[h].v});
        }
      }
      h = eg.nxt;
    }
  }
  cout << dis[e] << endl;
}

int main() {
  int t, c, s, e;
  cin >> t >> c >> s >> e;
  init();
  for (int i = 0; i < c; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    addEdge(u, v, w);
    addEdge(v, u, w);
  }
  dij(s, e);
  return 0;
}