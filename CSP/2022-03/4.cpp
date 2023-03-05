//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll n, m;

class node {
public:
    vector<vector<ll>> rnode;

    node() {
        rnode.resize(n + 1);
        for (ll i = 0; i < rnode.size(); ++i) {
            rnode[i].resize(m);
        }
    }


};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    vector<node> nodes(n + 1);
    for (ll i = 0; i < m; ++i) {
        ll k;
        cin >> k;
        for (ll j = 0; j < k; ++j) {
            ll u, v, x, y;
            cin >> u >> v >> x >> y;
            for (ll l = i; l <= i + y - 1; ++l) {
                nodes[u].rnode[v][l] += x;
                nodes[v].rnode[u][l] += x;
            }
        }
        ll l;
        cin >> l;
        map<ll,ll>mp;
        for (ll j = 0; j < l; ++j) {
            ll id;
            cin >> id;
            ll idx = 0;
            ll mx = 0;
            for (ll i1 = 1; i1 < nodes[id].rnode.size(); ++i1) {
                if (nodes[id].rnode[i1][i] > mx) {
                    idx = i1;
                    mx = nodes[id].rnode[i1][i];
                }
            }
            mp[id] = idx;
            cout << idx << endl;
//            res2.push_back(idx);
        }
        ll p, q;
        cin >> p >> q;
        if (p != 0) {
            ll cnt = 0;
            for (ll j = 1; j < nodes.size(); ++j) {
                ll flag = true;
                for (ll i1 = 1; i1 < nodes[j].rnode.size(); ++i1) {
                    if (nodes[j].rnode[i1][i] != 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    cnt++;
                }
            }
            cout << cnt << endl;
        }
        if (q != 0) {
            ll cnt = 0;
            for (ll j = 1; j < nodes.size(); ++j) {
                ll idx = 0;
                ll mx = 0;
                for (ll i1 = 1; i1 < nodes[j].rnode.size(); ++i1) {
                    if (nodes[j].rnode[i1][i] > mx) {
                        idx = i1;
                        mx = nodes[j].rnode[i1][i];
                    }
                }
                mp[j] = idx;
            }

            for (ll j = 1; j < nodes.size(); ++j) {
                if(mp.count(j)){
                    if(mp.count(mp[j])){
                        if(j==mp[mp[j]]){
                            cnt++;
                        }
                    }
                }
            }
            cout << cnt / 2 << endl;
        }
    }
    return 0;
}
