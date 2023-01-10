//
// Created by Administrator on 2023年01月08日0008.
//
#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e6 + 10;

vector<int> div(vector<int> a, int b, int &r) {
    vector<int> c;
    for (int i = a.size() - 1; i >= 0; --i) {
        r = r * 10 + a[i];
        c.push_back(r / b);
        r %= b;
    }
    reverse(c.begin(), c.end());
    while (c.size() > 1 && c.back() == 0)c.pop_back();
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    string str1;
    cin >> str1;
    vector<int> a;
    int b;
    cin >> b;
    for (int i = str1.size() - 1; i >= 0; i--) {
        a.push_back(str1[i] - '0');
    }
    int r = 0;
    vector<int> c = div(a, b, r);

    for (int i = c.size() - 1; i >= 0; --i) {
        cout << c[i];
    }
    cout << "\n" << r << endl;
    return 0;
}