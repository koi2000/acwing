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
        int n;
        cin >> n;
        pii arr[n];
        int maxx = -1;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            arr[i] = {x, y};
            maxx = max(maxx, y);
        }
        int arrs[maxx + 1];
        memset(arrs, 0, sizeof arrs);
        for (int i = 0; i < n; ++i) {
            pii t = arr[i];
            arrs[t.first - 1] += 1;
            arrs[t.second - 1] -= 1;
        }
        for (int i = 1; i < maxx + 1; ++i) {
            arrs[i] += arrs[i - 1];
        }
        cout << *max_element(arrs, arrs + maxx + 1) << endl;
    }
    return 0;
}
