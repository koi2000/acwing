//
// Created by DELL on 2023/9/4.
//
#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 1e6 + 10;
int head[N];
int vis[N];
struct edge {
    int u, v, w, nxt;
};
edge edges[4 * N];
int tot;

void init(int n = N) {
    memset(head, -1, 4 * (n + 1));
    memset(vis, 0, 4 * (n + 1));
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot++;
}

void topsort() {

}

int main() {
    int T;
    cin >> T;
    while (T--) {

        int n, m;
        cin >> n >> m;
        init(n);
        vector<pii > es;
        int d[n + 1];
        memset(d, 0, sizeof d);
        for (int i = 0; i < m; ++i) {
            int t, x, y;
            cin >> t >> x >> y;
            if (t == 0) {
                es.emplace_back(x, y);
            } else {
                addEdge(x, y, 1);
                d[y]++;
            }
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (d[i] == 0)q.push(i);
        }
        int idx = 0;
        int pos[n + 1];
        while (!q.empty()) {
            int nd = q.front();
            q.pop();
            int h = head[nd];
            pos[nd] = idx++;
            while (h != -1) {
                edge e = edges[h];
                if (--d[e.v] == 0) {
                    q.push(e.v);
                }
                h = e.nxt;
            }
        }
        if (idx != n) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 1; i <= n; ++i) {
                for (int j = head[i]; j != -1; j = edges[j].nxt) {
                    cout << i << " " << edges[j].v << endl;
                }
            }
            for (int i = 0; i < es.size(); ++i) {
                if (pos[es[i].first] < pos[es[i].second]) {
                    cout << es[i].first << " " << es[i].second << endl;
                } else {
                    cout << es[i].second << " " << es[i].first << endl;
                }

            }
        }
    }
    return 0;
}

