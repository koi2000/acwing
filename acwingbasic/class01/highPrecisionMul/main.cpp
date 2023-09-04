//
// Created by Administrator on 2023年01月08日0008.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e6 + 10;

vector<int> mul(vector<int> a, int b) {
    int t = 0;
    vector<int> c;
    for (int i = 0; i < a.size() || t; ++i) {
        if (i < a.size()) {
            t += a[i] * b;
        }
        c.push_back(t % 10);
        t /= 10;
    }
    while (c.size() > 1 && c.back() == 0) {
        c.pop_back();
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    string str1;
    int b;
    cin >> str1;
    cin >> b;
    vector<int> a;
    for (int i = str1.size() - 1; i >= 0; i--) {
        a.push_back(str1[i] - '0');
    }
    vector<int> c = mul(a, b);

    for (int i = c.size() - 1; i >= 0; --i) {
        cout << c[i];
    }
    return 0;
}