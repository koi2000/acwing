#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 310;

int r, c;
int mat[N][N];
int f[N][N];
int d[4][2] = {{-1, 0},
               {0,  1},
               {1,  0},
               {0,  -1}};

int dfs(int x, int y) {
    int &v = f[x][y];
    if (v != -1)return v;
    v = 1;
    for (int i = 0; i < 4; ++i) {
        int dx = x + d[i][0];
        int dy = y + d[i][1];
        if (dx >= 1 && dx <= r && dy >= 1 && dy <= c && mat[x][y] > mat[dx][dy]) {
            v = max(v, dfs(dx, dy) + 1);
        }
    }
    return v;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> mat[i][j];
        }
    }
    memset(f, -1, sizeof f);
    int res = 0;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            res = max(res, dfs(i, j));
        }
    }
    cout << res << endl;
    return 0;
}
