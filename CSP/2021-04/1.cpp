//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, L;
    cin >> n >> m >> L;
    map<int, int> mm;
    for (int i = 0; i < n * m; ++i) {
        int tp;
        cin >> tp;
        mm[tp]++;
    }
    for (int i = 0; i < L; ++i) {
        cout << mm[i] << " ";
    }
    return 0;
}