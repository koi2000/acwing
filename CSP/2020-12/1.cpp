//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int w, s;
        cin >> w >> s;
        sum += s * w;
    }
    cout << max(0, sum) << endl;
    return 0;
}
