//
// Created by DELL on 2023/6/27.
//
#include "bits/stdc++.h"

#define pii pair<int,int>
#define ll long long
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int m, n;
        cin >> m >> n;
        set<int> mach;
        set<int> allo;
        for (int i = 0; i < n; ++i) {
            int tp;
            cin >> tp;
            allo.insert(tp);
        }
        for (int i = 0; i < m; ++i) {
            int tp;
            cin >> tp;
            mach.insert(tp);
        }
        int cnt = 0;
        for (auto it = allo.rbegin();it!=allo.rend();it++){
            auto iter = mach.upper_bound(*it);
            if(iter!=mach.end()){
                cnt++;
                mach.erase(iter);
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
