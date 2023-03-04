//
// Created by DELL on 2023/3/3.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    int sum = a + b;
    bool neg = sum < 0;
    string str = to_string(abs(sum));
    vector<char> res;
    for (int i = str.size() - 1, j = 1; i >= 0; --i, j++) {
        res.push_back(str[i]);
        if (j % 3 == 0 && i != 0) {
            res.push_back(',');
        }
    }
    if (neg)cout << '-';
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i];
    }
    return 0;
}

