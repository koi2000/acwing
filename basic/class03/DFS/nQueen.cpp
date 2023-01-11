#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 20;

char mat[N][N];
bool col[N], dg[N], udg[N];
int n;

void dfs(int u) {
    if (u == n) {
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < n; ++j) {
////                cout << mat[i][j] << " ";
//                puts(mat[i]);
//            }
//            cout << "\n";
//        }
        for (int i = 0; i < n; ++i) {
            puts(mat[i]);
        }
        puts("");
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (!col[i] && !dg[u + i] && !udg[n - u + i]) {
            mat[u][i] = 'Q';
            col[i] = true;
            dg[u + i] = true;
            udg[n - u + i] = true;
            dfs(u + 1);
            mat[u][i] = '.';
            col[i] = false;
            dg[u + i] = false;
            udg[n - u + i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}
