//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
double f[1 << 20][105];
vector<double> p;
int n, k;

double dp(int s, int t) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s >> i & 1)cnt++;
    }
    if ((n - cnt) * k <= t)return 0;
    if (f[s][t])return f[s][t];
    for (int i = 0; i < n; ++i) {
        if (s >> i & 1) {
            f[s][t] += p[i] * (dp(s, t + 1) + 1);
        } else {
            f[s][t] += p[i] * (dp(s | (1 << i), t) + 1);
        }
    }
    return f[s][t];
}

int main() {
    //ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    p.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    printf("%.10f", dp(0, 0));
    return 0;
}
