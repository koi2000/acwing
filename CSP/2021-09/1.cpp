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
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> maxa(n);
    vector<int> mina(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    maxa[0] = b[0];
    mina[0] = b[0];
    for (int i = 1; i < n; ++i) {
        maxa[i] = b[i];
        if (b[i] > b[i - 1]) {
            mina[i] = b[i];
        } else {
            mina[i] = 0;
        }

    }
    int xsum = 0;
    int nsum = 0;
    for (int i = 0; i < n; ++i) {
        xsum += maxa[i];
        nsum += mina[i];
    }
    cout << xsum << endl;
    cout << nsum << endl;
    return 0;
}