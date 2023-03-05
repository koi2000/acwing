//
// Created by DELL on 2022/6/7.
//
#include <bits/stdc++.h>

#define ll long long
using namespace std;
struct num {
    int val = 0x3f;
    bool isInit = false;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    num arr[n + 1];
    int cnt = 0;
    for (int i = 1; i <= k; ++i) {
        int l, r;
        cin >> l >> r;
        if(r==0){

        } else if (!arr[r].isInit) {
            cnt++;
        }
        arr[l].val = arr[r].val;
        arr[l].isInit = true;
    }
    cout << cnt << endl;
    return 0;
}