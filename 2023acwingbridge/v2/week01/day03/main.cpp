//
// Created by DELL on 2023/9/4.
//
#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;
string str;

bool check(int len) {
    unordered_set<string> st;
    for (int i = 0; i < str.size() - len + 1; ++i) {
        string s = str.substr(i, len);
        if (st.count(s))return false;
        st.insert(s);
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    cin >> str;
    int l = 0;
    int r = str.size()+1;
    while (r - l > 1) {
        int mid = (r + l) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}

