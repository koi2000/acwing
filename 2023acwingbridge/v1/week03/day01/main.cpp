//
// Created by DELL on 2023/3/1.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int M = 3e5 + 10;
const int N = M * 32;

int n, m;
int s[M];
int son[N][2], cnt[N], idx;

void insert(int x, int y) {
    int p = 0;
    for (int i = 30; i >= 0; --i) {
        int u = x >> i & 1;
        if (!son[p][u])son[p][u] = ++idx;
        p = son[p][u];
        cnt[p] += y;
    }
}

int query(int x) {
    int res = 0, p = 0;
    for (int i = 30; i >= 0; --i) {
        int u = x >> i & 1;
        if (cnt[son[p][!u]]) {
            p = son[p][!u];
            res = res * 2 + 1;
        } else {
            p = son[p][u];
            res = res * 2;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        int tp;
        cin >> tp;
        s[i] = s[i - 1] ^ tp;
    }
    int res = 0;
    insert(s[0], 1);
    for (int i = 1; i <= n; ++i) {
        if (i - m - 1 >= 0) {
            insert(s[i - m - 1], -1);
        }
        res = max(res, query(s[i]));
        insert(s[i], 1);
    }
    cout << res << endl;
    return 0;
}

