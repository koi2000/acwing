#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

int ints[8][8];
int mat[8][8];
bool vis[8][8];

pii get_next(pii now) {
    pii nxt;
    vis[now.first][now.second] = true;
    if (vis[7][0]) {
        if (now.second == 7) {
            if (now.first % 2 == 1) {
                nxt = {now.first + 1, now.second};
            } else {
                nxt = {now.first + 1, now.second - 1};
            }
        } else if (now.first == 7) {
            if (now.second % 2 == 0) {
                nxt = {now.first, now.second + 1};
            } else {
                nxt = {now.first - 1, now.second + 1};
            }
        } else {
            if (vis[now.first - 1][now.second + 1]) {
                nxt = {now.first + 1, now.second - 1};
            } else if (vis[now.first + 1][now.second - 1]) {
                nxt = {now.first - 1, now.second + 1};
            }
        }
        return nxt;
    }
    if (now.first == 0) {
        if (now.second % 2 == 0) {
            nxt = {0, now.second + 1};
        } else {
            nxt = {now.first + 1, now.second - 1};
        }
    } else if (now.second == 0) {
        if (now.first % 2 == 1) {
            nxt = {now.first + 1, 0};
        } else {
            nxt = {now.first - 1, now.second + 1};
        }
    } else {
        if (vis[now.first - 1][now.second + 1]) {
            nxt = {now.first + 1, now.second - 1};
        } else if (vis[now.first + 1][now.second - 1]) {
            nxt = {now.first - 1, now.second + 1};
        }
    }
    return nxt;
}

int main() {
    ios::sync_with_stdio(false);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            cin >> ints[i][j];
        }
    }
    int n;
    cin >> n;
    int t;
    cin >> t;
    pii pos = {0, 0};
    for (int i = 0; i < n; ++i) {
        int tp;
        cin >> tp;
        if (pos.first < 8 && pos.second < 8) {
            mat[pos.first][pos.second] = tp;
        }
        pos = get_next(pos);
    }
    if (t == 0) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            mat[i][j] *= ints[i][j];
        }
    }
    if (t == 1) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    int res[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            double re = 0;
            for (int u = 0; u < 8; ++u) {
                for (int v = 0; v < 8; ++v) {
                    double w = 1;
                    if (u == 0)w /= sqrt(2);
                    if (v == 0)w /= sqrt(2);
                    re += mat[u][v] * w * cos((i + 0.5) * u * acos(-1) / 8) * cos((j + 0.5) * v * acos(-1) / 8);
                }
            }
            double tt = (128 + re / 4);
            if (tt-(int)tt>=0.5){
                res[i][j] = ceil(tt);
            }else{
                res[i][j] = floor(tt);
            }
//            res[i][j] = (int) (128 + re / 4);
            if (res[i][j] > 255)res[i][j] = 255;
            if (res[i][j] < 0)res[i][j] = 0;
        }
    }
    if (t == 2) {
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
