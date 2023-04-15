#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 10010;
struct edge {
    int u, v, w, nxt;
};
int head[N];
edge edges[4 * N];
int tot = 0;
bool vis[N];
int n, T;
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

int bfs(int u, char c) {
    queue<pii > q;
    q.push({u, 0});
    //int res = -1;
    pii res = {-1,u};
    memset(vis, 0, 4 * (n + 1));
    while (!q.empty()) {
        pii hd = q.front();
        q.pop();
        if (hd.second > res.first) {
            res.first = hd.second;
            res.second = hd.first;
        }
        if (vis[hd.first])continue;
        vis[hd.first] = 1;
        int h = head[hd.first];
        while (h != -1) {
            edge e = edges[h];
            if (c == 'l') {
                if (e.v < hd.first) {
                    q.push({e.v, hd.second + 1});
                }
            } else {
                if (e.v > hd.first) {
                    q.push({e.v, hd.second + 1});
                }
            }
            h = edges[h].nxt;
        }
    }
    return res.second;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> T;
    init();
    while (T--) {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'Q') {
            cout << bfs(x, 'l') << " " << bfs(x, 'r') << endl;
        } else if (c == 'L') {
            if (x >= 2) {
                addEdge(x, x - 1, 1);
                addEdge(x - 1, x, 1);
            }

        } else {
            if (x < n) {
                addEdge(x, x + 1, 1);
                addEdge(x + 1, x, 1);
            }
        }
    }
    return 0;
}
