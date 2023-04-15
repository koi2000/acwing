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
int n;
string colors;

void dfs(int x, int y, set<char> &st) {
    if (vis[x]) {
        return;
    }
    int h = head[x];
    vis[x] = true;
    st.insert(colors[x - 1]);
    while (h != -1) {
        edge e = edges[h];
        if (e.v != y) {
            dfs(e.v, y, st);
        }
        h = e.nxt;
    }
}

int main() {
    ios::sync_with_stdio(false);
    init();
    cin >> n;
    vector<pii > es;
    for (int i = 2; i <= n; ++i) {
        int x;
        cin >> x;
        es.emplace_back(i, x);
        addEdge(i, x, 1);
        addEdge(x, i, 1);
    }
    cin >> colors;
    int sum = 0;
    for (int i = 0; i < es.size(); ++i) {
        set<char> st;
//        st.insert(colors[es[i].first - 1]);
        dfs(es[i].first, es[i].second, st);
        int num1 = st.size();
        st.clear();
        memset(vis,0,sizeof vis);
//        st.insert(colors[es[i].second - 1]);
        dfs(es[i].second, es[i].first, st);
        int num2 = st.size();
        if (num1 == 3 && num2 == 3) {
            sum++;
        }
    }
    cout << sum << endl;
    return 0;
}
