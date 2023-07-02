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
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        set<int> res;
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        int maxlen = 1;
        for (int i = 0; i < n; ++i) {
            int maxx = arr[i];
            int minn = arr[i];
            for (int j = i; j < n; ++j) {
                maxx = max(maxx, arr[j]);
                minn = min(minn, arr[j]);
                if (maxx - minn <= k) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        cout << maxlen << endl;
    }
    return 0;
}
