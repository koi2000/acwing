//
// Created by Administrator on 2023年01月09日0009.
//
#include "bits/stdc++.h"

using namespace std;
int mat[1010][1010];
int sum[1010][1010];

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mat[i][j];
        }
    }
    memset(sum, 0, sizeof sum);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mat[i][j];
        }
    }
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1] << endl;
    }
    return 0;
}