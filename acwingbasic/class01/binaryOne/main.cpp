#include "bits/stdc++.h"

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        ll res = 0;
        int tp = a[i];
        while (tp) {
            res += (tp & 1);
            tp = tp >> 1;
        }
        cout << res << " ";
    }
    return 0;
}
