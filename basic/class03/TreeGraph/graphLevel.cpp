//
// Created by DELL on 2023/1/11.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e5 + 10, M = N * 2;
int n, m;
int head[N];
int edges[M];
int nxt[M];
int idx;
bool vis[N];
int d[N];
int ans = N;

void add(int a, int b) {
    edges[idx] = b;
    nxt[idx] = head[a];
    head[a] = idx++;
}

int bfs() {
    memset(d, -1, sizeof d);

    queue<int> q;
    d[1] = 0;
    q.push(1);
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = head[t]; i != -1; i = nxt[i]) {
            int j = edges[i];
            if (d[j] == -1) {
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }
    return d[n];
}

int main() {
    ios::sync_with_stdio(false);
    memset(head, -1, sizeof head);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
//        add(b, a);
    }
    cout << bfs();
    return 0;
}
