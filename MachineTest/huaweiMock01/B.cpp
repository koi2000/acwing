//
// Created by DELL on 2023/4/14.
//

#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    set<int> res;
    for (int i = 0; i < n; ++i) {
        int tp;
        cin >> tp;
        res.insert(tp);
    }
    for (auto it: res) {
        cout << it << endl;
    }
    return 0;
}
