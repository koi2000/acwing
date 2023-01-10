//
// Created by Administrator on 2023年01月09日0009.
//
#include "bits/stdc++.h"

using namespace std;
int mat[1010][1010];
int sum[1010][1010];
int diff[1010][1010];

void add(int x1, int y1, int x2, int y2, int c) {
    diff[x1][y1] += c;
    diff[x2 + 1][y1] -= c;
    diff[x1][y2 + 1] -= c;
    diff[x2 + 1][y2 + 1] += c;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mat[i][j];
            add(i, j, i, j, mat[i][j]);
        }
    }

    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        add(x1, y1, x2, y2, c);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + diff[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}