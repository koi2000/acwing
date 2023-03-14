//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
#define pii pair<int,int>

using namespace std;
int n;
struct msg {
    int u, d, r;
};
// 需要维护一个风险地区列表
// key为地区编号，value为时间界限
map<int, pii > region;
// key为用户编号 value为天-》地点
map<int, map<int, int>> users;
// 每一天得到的信息集合
map<int, vector<msg>> t2msg;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int t = 0; t < n; t++) {
        int r, m;
        cin >> r >> m;
        for (int i = 0; i < r; ++i) {
            int tp;
            cin >> tp;
            if (region.count(tp)) {
                if (t <= region[tp].second + 1) {
                    region[tp].second = tp + 6;
                }else {
                    region[tp].first = t;
                    region[tp].second = t + 6;
                }
            } else {
                region[tp].first = t;
                region[tp].second = t + 6;
            }
        }
//        for (auto it = region.begin(); it != region.end();) {
//            if (it->second.second < t) {
//                region.erase(it++);
//            } else {
//                it++;
//            }
//        }
        for (int i = 0; i < m; ++i) {
            int td, tu, tr;
            cin >> td >> tu >> tr;
            users[tu][td] = tr;
            t2msg[t].push_back({tu, td, tr});
        }
        set<int> res;
        for (int d0 = t - 6; d0 <= t; ++d0) {
            for (int i = 0; i < t2msg[d0].size(); ++i) {
                msg mg = t2msg[d0][i];
                if (mg.d >= t - 6 && mg.d <= t) {
                    if (region.count(mg.r)) {
                        pii re = region[mg.r];
                        if (re.first <= mg.d && re.second >= t) {
                            res.insert(mg.u);
                            //break;
                        }
                    }
                }
            }
        }
//        for (auto &u:users) {
//            map<int,int > usrSet = u.second;
//
//            for (auto it = usrSet.upper_bound(t - 7);; it++) {
//                if(region.count(it->second)){
//                    pii re = region[it->second];
//                    if (it->first >= re.first && t <= re.second) {
//                        res.insert(u.first);
//                        break;
//                    }
//                }
//                if (it == usrSet.lower_bound(t)) {
//                    break;
//                }
//            }
//        }
        cout << t << " ";
        for (auto id:res) {
            cout << id << " ";
        }
        cout << "\n";
    }
    return 0;
}
