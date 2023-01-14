//
// Created by DELL on 2023/1/11.
//
#include "bits/stdc++.h"

using namespace std;

const int N = 510, M = 100010;

int n1, n2, m;
int head[N], edges[M], nxt[M], idx;
int match[N];
bool vis[N];

void add(int a, int b) {
    edges[idx] = b;
    nxt[idx] = head[a];
    head[a] = idx++;
}

bool find(int x) {
    for (int i = head[x]; i != -1; i = nxt[i]) {
        int j = edges[i];
        if (!vis[j]) {
            vis[j] = true;
            if (match[j] == 0 || find(match[j])) {
                match[j] = x;
                return true;
            }
        }
    }
    return false;
}

int main() {
    cin >> n1 >> n2 >> m;
    memset(head, -1, sizeof head);
    while (m--) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }
    int res = 0;
    for (int i = 1; i <= n1; ++i) {
        memset(vis, 0, sizeof vis);
        if (find(i)) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}

