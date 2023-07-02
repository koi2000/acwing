//
// Created by DELL on 2023/6/27.
//
#include "bits/stdc++.h"

#define pii pair<int,int>
#define ll long long
using namespace std;
int maxlen = 0;
int mat[510][510];
int smat[510][510];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> mat[i][j];
            smat[i][j] = mat[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {

        for (int j = 1; j <= m; ++j) {
            smat[i][j] = mat[i][j] + smat[i - 1][j] + smat[i][j - 1] - smat[i - 1][j - 1];
        }
    }
    int maxx = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int x = 0; x + i <= n; ++x) {
                for (int y = 0; y + j <= m; ++y) {
                    int num = smat[i + x][j + y] - smat[i + x][j - 1] - smat[i - 1][j + y] + smat[i - 1][j - 1];
                    if (num == (x + 1) * (y + 1)) {
                        maxx = max(maxx, num);
                    }
                }
            }
        }
    }
    cout << maxx << endl;
    return 0;
}
