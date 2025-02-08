//
// Created by DELL on 2023/9/4.
//
//#pragma GCC optimize(3)
#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 1e6 + 10;
int n, m;
int f[N];

void init() {
    for (int i = 0; i < N; ++i) {
        f[i] = i;
    }
}

int find(int x) {
    if (x == f[x]) {
        return x;
    }
    f[x] = find(f[x]);
    return f[x];
}

inline void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    f[fx] = fy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //init();
    cin >> n >> m;
    for (int i = 0; i <= n; ++i) {
        f[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        int root1=find(x);
        int root2=find(y);
        if(root1!=root2)f[root2]=root1;
        //merge(x, y);
    }
    int q;
    cin >> q;
    int x, y;
    for (int i = 0; i < q; ++i) {
        cin >> x >> y;
        puts(find(x)==find(y)?"Yes":"No");
    }
    return 0;
}

