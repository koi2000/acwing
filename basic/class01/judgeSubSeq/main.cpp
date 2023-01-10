#include "bits/stdc++.h"

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int a[n];
    int b[m];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int j = 0;
    for (int i = 0; i < m; ++i) {
        if (b[i] == a[j]) {
            j++;
            if (j == n) {
                break;
            }
        }
    }
    if (j == n) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
