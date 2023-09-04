//
// Created by DELL on 2023/3/1.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e6 + 10;

struct edge {
    int u, v, w, nxt;

    edge() {}

    edge(int u, int v) : u(u), v(v) {}
};

int head[N];
edge edges[4 * N];
int tot = 0;
int n, m;
int d[N];
queue<int> q;
edge e[N];
int pos[N];

void init() {
    memset(head, -1, sizeof head);
}

void addEdge(int u, int v, int w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot;
    tot++;
}

bool toto() {
    queue<int> qq;
    for (int i = 1; i <= n; ++i) {
        if (d[i] == 0) {
            qq.push(i);
        }
    }
    int idx = 0;
    while (!qq.empty()) {
        int nd = qq.front();
        qq.pop();
        q.push(nd);
        int h = head[nd];
        pos[nd] = idx;
        idx++;
        while (h != -1) {
            edge e = edges[h];
            if (--d[e.v] == 0) {
                qq.push(e.v);
            }
            h = edges[h].nxt;
        }
    }
    return q.size() == n;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int t, x, y;
        memset(d, 0, (n + 1) * sizeof(int));
        memset(head, -1, (n + 1) * sizeof(int));
        tot = 0;
        int k = 0;
        while (!q.empty()) {
            q.pop();
        }
        for (int i = 1; i <= m; ++i) {
            cin >> t >> x >> y;
            if (t == 1) {
                addEdge(x, y, 1);
                d[y]++;
            } else {
                e[k++] = edge(x, y);
            }

        }
        if (!toto()) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;

            for (int i = 1; i <= n; ++i) {
                for (int j = head[i]; j != -1; j = edges[j].nxt) {
                    cout << i << " " << edges[j].v << endl;
                }
            }
//            cout<<endl;
//            int idx = 0;
//            while (!q.empty()) {
//                int tp = q.front();
//                pos[tp] = idx;
//                idx++;
//                q.pop();
//            }
            for (int i = 0; i < k; ++i) {
                int u = e[i].u;
                int v = e[i].v;
                if (pos[u] > pos[v]) {
                    int tp = u;
//                    u = v;
//                    v = tp;
                    swap(u, v);
                }
                cout << u << " " << v << endl;
            }
        }
    }
    return 0;
}

