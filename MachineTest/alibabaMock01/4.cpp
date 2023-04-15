//
// Created by DELL on 2023/4/14.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
int n, m;
char mat[510][510];
pii st;
pii ed;
bool vis[510][510];
int dir[4][2] = {{1,  0},
                 {0,  1},
                 {-1, 0},
                 {0,  -1}};

bool check(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return true;
    }
    return false;
}

int res = INT_MAX;

void bfs() {
    queue<pair<pii, pii>> q;
    q.push({st, {0, 0}});
    while (!q.empty()) {
        auto node = q.front();
        pii now = node.first;
        if (now == ed) {
            res = node.second.second;
            return;
        }
        q.pop();
        if (vis[now.first][now.second])continue;
        vis[now.first][now.second] = 1;
        for (int i = 0; i < 4; ++i) {
            int dx = now.first + dir[i][0];
            int dy = now.second + dir[i][1];
            if (check(dx, dy) && mat[dx][dy] != '#') {
                q.push({{dx,                dy},
                        {node.second.first, node.second.second + 1}});
            }
        }
        if (node.second.first < 5) {
            int dx = n - now.first - 1;
            int dy = m - now.second - 1;
            if (check(dx, dy) && mat[dx][dy] != '#') {
                q.push({{dx,                    dy},
                        {node.second.first + 1, node.second.second + 1}});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ++j) {
            cin >> mat[i][j];
            if (mat[i][j] == 'S') {
                st = {i, j};
            }
            if (mat[i][j] == 'E') {
                ed = {i, j};
            }
        }
    }
    bfs();
    res = res==INT_MAX?-1:res;
    cout << res << endl;
    return 0;
}

