#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int N = 1e5 + 10;

int a[N];
int b[N];

int main() {
    ios::sync_with_stdio(false);
    int n, m, x;
    cin >> n >> m >> x;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i = 0, j = m - 1; i < n; ++i) {
        while (j >= 0 && a[i] + b[j] > x) j--;
        if (j >= 0 && a[i] + b[j] == x) {
            cout << i << " " << j << endl;
        }
    }
    return 0;
}
