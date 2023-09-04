//
// Created by DELL on 2023/1/11.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;

const int N = 110;
const int M = 110;
int mat[N][M];
int vis[N][M];
int n, m;
int res = INT_MAX;

bool check(int x, int y) {
    if (x < n && y < m && x >= 0 && y >= 0) {
        return mat[x][y] == 0;
    }
    return false;
}

void fbfs(int x, int y, int depth) {
    if (x == n - 1 && y == m - 1) {
//        cout << depth;
        res = min(depth, res);
        return;
    }
    if (check(x + 1, y)) {
        vis[x + 1][y] = 1;
        fbfs(x + 1, y, depth + 1);
//        vis[x + 1][y] = 0;
    }
    if (check(x - 1, y)) {
        vis[x - 1][y] = 1;
        fbfs(x - 1, y, depth + 1);
//        vis[x - 1][y] = 0;
    }
    if (check(x, y - 1)) {
        vis[x][y - 1] = 1;
        fbfs(x, y - 1, depth + 1);
//        vis[x][y - 1] = 0;
    }
    if (check(x, y + 1)) {
        vis[x][y + 1] = 1;
        fbfs(x, y + 1, depth + 1);
//        vis[x][y + 1] = 0;
    }
}

typedef pair<int, int> PII;
int d[N][M];

int bfs() {
    queue<PII> q;
    memset(d, -1, sizeof d);
    d[0][0] = 0;
    q.push({0, 0});
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (check(x, y) && d[x][y] == -1) {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }
    return d[n-1][m-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
        }
    }
    cout << bfs();
    return 0;
}
