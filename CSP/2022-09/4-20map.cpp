//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
#define pii pair<int,int>
const int N = 10000;
int n, m, q;
//vector<int> user(N, 0);
// 用户投票的映射
map<int, int> user;
// 每个吉祥物有哪些用户投票
//map<int, set<int>> obj;

map<int,pii>obj;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;

    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, x;
            cin >> l >> r >> x;

        } else if (op == 2) {
            int x, w;
            cin >> x >> w;
            if(w!=0){
                for (auto &it:user) {
                    if (it.second == x) {
                        it.second = w;
                    }
                }
            }else{
                for (auto it=user.begin();it!=user.end();){
                    if (it->second==x){
                        user.erase(it++);
                    }else{
                        it++;
                    }
                }
            }

            //obj[w].insert(obj[x].begin(),obj[x].end());
            //obj[x].clear();
        } else if (op == 3) {
            int x, y;
            cin >> x >> y;
            for (auto &it:user) {
                if (it.second == x) {
                    it.second = y;
                } else if (it.second == y) {
                    it.second = x;
                }
            }
            //auto tp = obj[x];
            //obj[x] = obj[y];
            //obj[y] = tp;
        } else if (op == 4) {
            int w;
            cin >> w;
            if (w == 0) {
                int us = user.size();
                cout << n - us << endl;
            }else{
                int cnt = 0;
                for (auto it:user) {
                    if (it.second == w)cnt++;
                }
                cout << cnt << endl;
            }

        } else {
            map<int, int> up;
            for (auto it:user) {
                if (up.count(it.second)) {
                    up[it.second]++;
                } else {
                    up[it.second] = 1;
                }
            }
            int mx = 1, res = 0;
            for (auto it:up) {
                if (it.second > mx) {
                    res = it.first;
                    mx = it.second;
                } /*else if (it.second == mx) {
                    res = min(it.first, res);
                }*/
            }
            cout << res << endl;
        }
    }

    return 0;
}
