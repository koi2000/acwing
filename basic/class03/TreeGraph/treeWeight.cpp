//
// Created by DELL on 2023/1/11.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e5 + 10, M = N * 2;
int n;
int head[N];
int edges[M];
int nxt[M];
int idx;
bool vis[N];

int ans = N;

void add(int a, int b) {
    edges[idx] = b;
    nxt[idx] = head[a];
    head[a] = idx++;
}

int dfs(int u) {
    vis[u] = true;
    int sum = 1, res = 0;
    for (int i = head[u]; i != -1; i = nxt[i]) {
        int j = edges[i];
        if (!vis[j]) {
            int s = dfs(j);
            res = max(res, s);
            sum += s;
        }
    }
    res = max(res, n - sum);
    ans = min(ans, res);
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    memset(head, -1, sizeof head);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans;
    return 0;
}
