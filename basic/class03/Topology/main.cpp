//
// Created by DELL on 2023/1/11.
//

#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e5 + 10, M = 2 * N;
int head[N];
int edges[M];
int nxt[N];
int idx;
int d[N];
int n, m;

int q[N];

void add(int a, int b) {
    edges[idx] = b;
    nxt[idx] = head[a];
    head[a] = idx++;
}

bool topsort2() {
    queue<int> q;
    int num = 0;
    for (int i = 1; i <= n; ++i) {
        if (!d[i]) {
            q.push(i);
            num++;
        }
    }
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = head[t]; i != -1; i = nxt[i]) {
            int j = edges[i];
            d[j]--;
            if (d[j] == 0) {
                q.push(j);
                num++;
            }
        }
    }
    return num == n;
}

bool topsort() {
    int tt = -1;
    int hh = 0;
    for (int i = 1; i <= n; ++i) {
        if (!d[i]) {
            q[++tt] = i;
        }
    }
    while (hh <= tt) {
        int t = q[hh++];
        for (int i = head[t]; i != -1; i = nxt[i]) {
            int j = edges[i];
            d[j]--;
            if (d[j] == 0) {
                q[++tt] = j;
            }
        }
    }
    return tt == n - 1;
}

int main() {
    ios::sync_with_stdio(false);
    memset(head, -1, sizeof head);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;
    }
    if (topsort()) {
        for (int i = 0; i < n; ++i) {
            cout<<q[i]<<" ";
        }
    } else {
        cout << -1 << endl;
    }
    return 0;
}
