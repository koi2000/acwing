//
// Created by DELL on 2023/1/11.
//
#include "bits/stdc++.h"

using namespace std;
const int N = 510, M = 10010;

struct edge {
    int u, v, w;
};
int n, m, k;
int dis[N];
int last[N];
edge edges[M];

void bellman() {
    memset(dis, 0x3f, sizeof dis);
    dis[1] = 0;
    for (int i = 0; i < k; ++i) {
        memcpy(last, dis, sizeof dis);
        for (int j = 0; j < m; ++j) {
            edge e = edges[j];
            dis[e.v] = min(dis[e.v], last[e.u] + e.w);
        }
    }

}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        edges[i] = {a, b, c};
    }
    bellman();
    if (dis[n] > 0x3f3f3f3f / 2) {
        cout << "impossible";
    } else {
        cout << dis[n];
    }
    return 0;
}
