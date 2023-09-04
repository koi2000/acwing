//
// Created by Administrator on 2023年01月08日0008.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e6 + 10;

vector<int> add(vector<int> a, vector<int> b) {
    if (a.size() < b.size()) {
        return add(b, a);
    }
    int t = 0;
    vector<int> c;
    for (int i = 0; i < a.size(); ++i) {
        t += a[i];
        if (i < b.size()) {
            t += b[i];
        }
        c.push_back(t % 10);
        t /= 10;
    }
    if (t)c.push_back(t);
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    string str1, str2;
    cin >> str1 >> str2;
    vector<int> a;
    vector<int> b;
    for (int i = str1.size() - 1; i >= 0; i--) {
        a.push_back(str1[i] - '0');
    }
    for (int i = str2.size() - 1; i >= 0; i--) {
        b.push_back(str2[i] - '0');
    }
    vector<int> c = add(a, b);

    for (int i = c.size() - 1; i >= 0; --i) {
        cout << c[i];
    }
    return 0;
}