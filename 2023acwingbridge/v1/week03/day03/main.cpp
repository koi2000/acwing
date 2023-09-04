//
// Created by DELL on 2023/3/1.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e6 + 10;

set<string> res;
int n, m, k;
int dir[4][2] = {{1,  0},
                 {0,  1},
                 {-1, 0},
                 {0,  -1}};
int mat[10][10];

bool check(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return true;
    }
    return false;
}

void dfs(int x, int y, int depth, string now) {
    if (depth > k + 1) {
        res.insert(now);
        return;
    }
    for (int i = 0; i < 4; ++i) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if (check(dx, dy)) {
            now[depth] = '0' + mat[dx][dy];
            dfs(dx, dy, depth + 1, now);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
    string str;
    for (int i = 0; i <= k; ++i) {
        str += '1';
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            dfs(i, j, 0, str);
        }
    }

//    for (auto &it:res) {
//        cout << it << endl;
//    }
    cout << res.size() << endl;
    return 0;
}

