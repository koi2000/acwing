#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include "bits/stdc++.h"
#define ll long long
using namespace std;


int main() {
//    ios::sync_with_stdio(false);
    int n, l, s;
//    cin >> n >> l >> s;
    scanf("%d %d %d", &n, &l, &s);
    set<pair<int, int>> tree;
    for (int i = 0; i < n; ++i) {
        int x, y;
//        cin >> x >> y;
        scanf("%d %d", &x, &y);
        tree.insert({x, y});
    }
    int map[s + 1][s + 1];
    int tp;
    for (int i = s; i >= 0; --i) {
        for (int j = 0; j <= s; ++j) {
            scanf("%d", &tp);
            map[i][j] = tp;
        }
    }
    int res = 0;
    for (auto tr:tree) {
        int flag = 1;
        for (int i = 0; i <= s; ++i) {
            for (int j = 0; j <= s; ++j) {
                int x = tr.first + i;
                int y = tr.second + j;
                if (x > l || y > l || tree.count({x, y}) != map[i][j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
        if (flag)res++;
    }
    cout << res << endl;
    return 0;
}

// Created by csp on 22-6-12.
//
//#include <bits/stdc++.h>
//
//#define ll long long
//#define lowbit(x) (x & -x)
//using namespace std;
//const int maxn = 1e6 + 10;
//
//unordered_map<int, set<int>> mapx;
//unordered_map<int, set<int>> mapy;
//
//int main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
//    int n, L, s;
//    cin >> n >> L >> s;
//    int x, y;
//    int mat[s + 1][s + 1];
//    for (int i = 0; i < n; ++i) {
//        cin >> x >> y;
//        mapx[x].insert(y);
//        mapy[y].insert(x);
//    }
//    int maps[s + 1][s + 1];
//    for (int i = s; i >= 0; --i) {
//        for (int j = 0; j <= s; ++j) {
//            cin >> maps[i][j];
//        }
//    }
//    int res = 0;
//    for (auto &item: mapx) {
//        set<int> col = item.second;
//        for (auto i: col) {
//            int flag = 1;
//            for (int j = 0; j < s + 1; ++j) {
//                for (int k = 0; k < s + 1; ++k) {
//                    int xx = item.first + j;
//                    int yy = i + k;
//                    if (xx > L || yy > L) {
//                        flag = 0;
//                        break;
//                    }
//                    if (maps[j][k]) {
//                        if (mapx.count(xx)) {
//                            if (mapx[xx].count(yy)) {
//                                continue;
//                            }
//                        }
//                    } else {
//                        if (!mapx.count(xx)) {
//                            continue;
//                        } else {
//                            if (!mapx[xx].count(yy)) {
//                                continue;
//                            }
//                        }
//                    }
//                    flag = 0;
//                    break;
//                }
//                if (flag == 0) {
//                    break;
//                }
//            }
//            if (flag) {
//                res++;
//            }
//        }
//    }
//    cout << res << endl;
//    return 0;
//}