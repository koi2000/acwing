//
// Created by DELL on 2023/9/4.
//
#include "bits/stdc++.h"

#define ll long long
#define pii pair<int,int>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n + 2, 0);
        for (int i = 1; i <= n; ++i) {
            int tp;
            cin >> tp;
            if (tp == 0)continue;
            tp = min(i, tp);
            arr[i + 1] -= 1;
            arr[i - tp + 1] += 1;
        }
        for (int i = 1; i <= n; ++i) {
            arr[i] += arr[i - 1];
        }
        for (int i = 1; i <= n; ++i) {
            cout << (arr[i] > 0) << " ";
        }
        cout << endl;
    }
    return 0;
}

