//
// Created by DELL on 2023/9/4.
//
#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;
int n;


void update(char &c) {
    if (c == 'W')c = 'B';
    else c = 'W';
}

bool check(string str, char c) {
    vector<int> res;
    for (int i = 0; i < n - 1; ++i) {
        if (str[i] != c) {
            update(str[i]);
            update(str[i + 1]);
            res.push_back(i);
        }
    }
    if (str.back() != c)return false;
    cout << res.size() << endl;
    for (int x:res)cout << x + 1 << ' ';
    if (!res.empty())cout << endl;
    return true;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        string str;
        cin >> str;
        if (!check(str, 'W') && !check(str, 'B')) {
            cout << "-1" << endl;
        }
    }
    return 0;
}

