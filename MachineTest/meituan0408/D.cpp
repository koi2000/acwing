#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
int n, m, k;
int mat[501][501];
int vis[501][501];
int dir[4][2] = {{1,  0},
                 {-1, 0},
                 {0,  1},
                 {0,  -1}};
int res = 0;
pii st;
pii ed;
set<pii > bom;

bool check(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return true;
    }
    return false;
}

int distance(int x1, int y1) {
    int rt = INT_MAX;
    for (auto item:bom) {
        int x2 = item.first;
        int y2 = item.second;
        rt = min(rt, abs(x1 - x2) + abs(y1 - y2));
    }
    return rt;
}

int ret = -1;

void bfs(int x, int y, int dis) {
    if (x == ed.first && y == ed.second) {
        ret = max(dis, ret);
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; ++i) {
        int dx = x + dir[i][0];
        int dy = y + dir[i][1];
        if (check(dx, dy) && !vis[dx][dy] && !bom.count({dx, dy})) {
            dis = min(dis, distance(dx, dy));
            bfs(dx, dy, dis);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        bom.insert({x - 1, y - 1});
    }
    cin >> st.first >> st.second;
    st.first--;
    st.second--;
    cin >> ed.first >> ed.second;
    ed.first--;
    ed.second--;
    bfs(st.first, st.second, INT_MAX);
    if (ret == -1) {
        cout << 0 << endl;
    } else {
        cout << ret << endl;
    }
    return 0;
}
