//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
int xl, xr, yb, yt;

bool isin(int x, int y) {
    return (x >= xl) && (x <= xr) && (y >= yb) && (y <= yt);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, t;
    cin >> n >> k >> t;
    cin >> xl >> yb >> xr >> yt;
    int cntp = 0;
    int cnts = 0;
    for (int i = 0; i < n; ++i) {
        int tpk = 0;
        int flag = false;
        int fd = false;
        for (int j = 0; j < t; ++j) {
            int x, y;
            cin >> x >> y;
            if (isin(x, y)) {
                if (!flag) {
                    flag = true;
                    cntp++;
                }
                tpk++;
            } else {
                tpk = 0;
            }
            if (tpk == k && !fd) {
                cnts++;
                fd = true;
                //break;
            }
        }
    }
    cout << cntp << "\n" << cnts;
    return 0;
}
