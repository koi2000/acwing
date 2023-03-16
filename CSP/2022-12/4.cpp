//
// Created by DEll on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const ll N = 300010;
struct edge {
    ll u, v, w, nxt;
};
edge edges[4 * N];
ll head[N];
ll tot = 0;
ll vis[N];
ll n;
ll dis[N];
ll number[N];

vector<vector<ll>> pre;
map<ll, vector<ll>> costs;

void init() {
    memset(head, -1, sizeof head);
    memset(vis, 0, sizeof vis);
    memset(dis, 0x3f, sizeof dis);
}

void addEdge(ll u, ll v, ll w) {
    edges[tot].u = u;
    edges[tot].v = v;
    edges[tot].w = w;
    edges[tot].nxt = head[u];
    head[u] = tot++;
}

map<ll, map<ll, ll>> mps;

// dfs找出所有子节点
// dfs找出以该点为根的所有子节点的时间出现的次数
map<ll, ll> dfs(ll u) {
//    if (mps.count(u))return mps[u];
    ll h = head[u];

    while (h != -1) {
        edge e = edges[h];
        if (mps[u].count(number[e.v])) {
            mps[u][number[e.v]]++;
        } else {
            mps[u][number[e.v]] = 1;
        }
        // arr.insert(e.v);
        map<ll, ll> ret = dfs(e.v);
//        if (ret.count(number[e.v])) {
//            ret[number[e.v]]++;
//        } else {
//            ret[number[e.v]] = 1;
//        }
        for (auto it:ret) {
            if (mps[u].count(it.first)) {
                mps[u][it.first] += it.second;
            } else {
                mps[u][it.first] = it.second;
            }
        }
        h = edges[h].nxt;
    }
    return mps[u];
}

map<ll, vector<ll>> mp;

vector<ll> get_child(ll u) {
    ll h = head[u];
    vector<ll> arr;
    arr.push_back(u);
    while (h != -1) {
        edge e = edges[h];
        //arr.push_back(e.v);
        vector<ll> ret = get_child(e.v);
        for (ll i:ret) {
            arr.push_back(i);
        }
        h = edges[h].nxt;
    }
    mp[u] = arr;
    return arr;
}

ll get_gs(vector<ll> v) {
    ll ans = 0;
    vector<ll> s;
    for (ll i = 0; i < v.size(); i++) {
        s.push_back(number[v[i]]);
    }
    if (s.size() == 1)
        return 0;
    sort(s.begin(), s.end());
    ll size = s.size();
    for (ll i = 0; i < size; i++) {
        ll tmp = 0x3f3f3f3f3f3f3f3f;
        if (i + 1 >= 0 && i + 1 < size)
            tmp = min((s[i + 1] - s[i]) * (s[i + 1] - s[i]), tmp);
        if (i - 1 >= 0 && i - 1 < size)
            tmp = min((s[i - 1] - s[i]) * (s[i - 1] - s[i]), tmp);
        ans += tmp;
    }
    return ans;
}

// 获取g的值
ll get_g(map<ll, ll> arr) {
    if (arr.empty())return 0;
    ll sum = 0;
    for (auto it = arr.begin(); it != arr.end(); ++it) {
        if (it->second > 1)continue;
        if (it == arr.begin()) {
            ll y = it->first;
            if (++it != arr.end()) {
                ll x = it->first;
                sum += (x - y) * (x - y);
            }
            it--;
            continue;
        }
        ll x = it->first;
        it--;
        ll y = it->first;
        it++;
        ll res1 = (x - y) * (x - y);
        if (++it != arr.end()) {
            y = it->first;
            res1 = min((x - y) * (x - y), res1);
        }
        it--;
        sum += res1;
    }
    return sum;
}

ll qpow(ll a, ll b, ll p) {
    ll s = 0;
    while (b) {
        if (b & 1)s = (s + a) % p;
        a = (a + a) % p;
        b >> 1;
    }
    return s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    init();
    for (ll i = 2; i <= n; ++i) {
        ll p;
        cin >> p;
        addEdge(p, i, 1);
    }
    for (ll i = 1; i <= n; ++i) {
        cin >> number[i];
    }
    get_child(1);
    for (ll i = 1; i <= n; ++i) {
        cout << get_gs(mp[i]) << endl;
    }
    return 0;
}
