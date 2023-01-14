//
// Created by DELL on 2023/1/11.
//
#include "bits/stdc++.h"

using namespace std;
const int N = 100010, M = 200010;

int n, m;
int head[N], edges[M], nxt[M], idx;
int color[N];

void add(int a, int b) {
    edges[idx] = b;
    nxt[idx] = head[a];
    head[a] = idx++;
}

bool dfs(int u, int c) {
    color[u] = c;
    for (int i = head[u]; i != -1; i = nxt[i]) {
        int j = edges[i];
        if (!color[j]) {
            if (!dfs(j, 3 - c))return false;
        } else {
            if (color[j] == c) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;
    memset(head, -1, sizeof head);
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    bool flag = true;
    for (int i = 1; i <= n; ++i) {
        if (!color[i]) {
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }
        }
    }
    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
