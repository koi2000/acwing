#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 505, INF = 1e9;
int mat[N][N];
int f[N][N];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= i + 1; ++j) {
            f[i][j] = -INF;
        }
    }
    f[1][1] = mat[1][1];
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            f[i][j] = max(f[i - 1][j - 1] + mat[i][j], f[i - 1][j] + mat[i][j]);
        }
    }
    int res = -INF;
    for (int i = 1; i <= n; ++i) {
        res = max(res, f[n][i]);
    }
    cout << res << endl;
    return 0;
}
