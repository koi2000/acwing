#include "bits/stdc++.h"

#define ll long long
#define pii pair<ll,ll>

using namespace std;
const ll N = 500000;

struct edge {
    ll u, v, w, nxt;

    bool operator<(const edge &rhs) const {
        return w < rhs.w;
    }

    bool operator>(const edge &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const edge &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const edge &rhs) const {
        return !(*this < rhs);
    }
};

edge edges[4 * N];
ll head[N];
ll tot = 0;
ll vis[N];
ll n, m;
ll dis[N];
pii node[N];
ll cost[N];
ll f[N];
ll k[N];

ll find(ll x) {
    if (x == f[x])return x;
    f[x] = find(f[x]);
    return f[x];
}

void merge(ll x, ll y) {
    ll fx = find(fx);
    ll fy = find(fy);
    f[fx] = f[y];
}


void init() {
    memset(head, -1, sizeof head);
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
    tot = 0;
}

void addEdge(ll u, ll v, ll w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot++;
}

ll sum = 0;
ll numbuild = 0;
set<ll> build;
set<pii > link;

ll kurl() {
    sort(edges, edges + tot);
    for (ll i = 0; i <= N; i++) f[i] = i;
    int num = 0;
    for (ll i = 0; i < tot; ++i) {
        ll a = edges[i].u, b = edges[i].v, w = edges[i].w;
        ll fa = find(a);
        ll fb = find(b);
        if (fa != fb) {
            f[fa] = fb;
            sum += w;
            num++;
            if (a == 0 || b == 0) {
                numbuild++;
                if (a == 0) {
                    build.insert(b);
                } else {
                    build.insert(a);
                }
            } else {
                ll minn = min(a, b);
                ll maxx = max(a, b);
                link.insert({minn, maxx});
            }
        }
        if (num == n)break;
    }
    return sum;
}

signed main() {
    ios::sync_with_stdio(false);
    init();
    cin >> n;
    for (ll i = 1; i <= n; ++i) {
        ll x, y;
        cin >> x >> y;
        node[i] = {x, y};
    }
    for (ll i = 1; i <= n; ++i) {
        cin >> cost[i];
    }
    for (ll i = 1; i <= n; ++i) {
        cin >> k[i];
    }
    for (ll i = 1; i <= n; ++i) {
        for (ll j = i + 1; j <= n; ++j) {
            ll len = abs(node[i].first - node[j].first)
                     + abs(node[i].second - node[j].second);
            ll w = (k[i] + k[j]) * len;
            addEdge(i, j, w);
        }
    }
    for (ll i = 1; i <= n; ++i) {
        addEdge(0, i, cost[i]);
//        addEdge(i, 0, cost[i]);
    }
    cout << kurl() << endl;
    cout << numbuild << endl;
    for (auto it:build) {
        cout << it << " ";
    }
    cout << endl;
    cout << n - numbuild << endl;
    for (auto it : link) {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}
