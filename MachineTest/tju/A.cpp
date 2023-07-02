//
// Created by DELL on 2023/6/27.
//
#include "bits/stdc++.h"

#define pii pair<int,int>
#define ll long long
using namespace std;

int main() {
    string T;
    getline(cin, T);
    int t = atoi(T.c_str());
    while (t--) {
        string str;
//        char ch[10000];
//        scanf("%s",&ch);
        getline(cin, str);
//        cin>>str;
        int len = str.size();
        int l = 0;
        int r = 0;
        string res = "";
        while (l < len && r < len) {
            if (str[l] == str[r]) {
                r++;
            } else {
                res += to_string(r - l);
                res += str[l];
                l = r;
                r = l + 1;
            }
        }
        if (str[l] == str[r - 1]) {
            res += to_string(r - l);
            res += str[l];
            l = r;
        }
        cout << res << endl;
    }
    return 0;
}
