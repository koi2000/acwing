//
// Created by DELL on 2023/4/14.
//
#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
int n, m;
int mat[104][104];

bool check(int x, int y) {
    if (x >= 0 && x < n && y >= 0 && y < m) {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> mat[i][j];
            }
        }
        int dp[n][m];
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int eng = mat[i][j];
                for (int k = 1; k <= eng; ++k) {
                    for (int x = 0; x <= k; ++x) {
                        int y = k - x;
                        int dx1 = i + x;
                        int dy1 = j + y;
                        if (check(dx1, dy1)) {
                            dp[dx1][dy1] = (dp[dx1][dy1] + dp[i][j]) % 10000;
                        }
                    }
                }

            }
        }
        cout << dp[n - 1][m - 1] << endl;
    }
    return 0;
}

