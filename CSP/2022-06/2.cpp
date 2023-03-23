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