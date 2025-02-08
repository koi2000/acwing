//
// Created by DELL on 2023/9/4.
//
#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    int l = 0;
    int r = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] != 'x') {
            l = i, r = i;
        } else {
            r++;
            if (r - l >= 3) {
                l++;
                res++;
            }
        }
    }
    cout << res << endl;
    return 0;
}

