#include "bits/stdc++.h"

#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    int arr[n + 1];
    int c[n + 1];
    c[0] = 1;
    int b[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
        c[i] = arr[i] * c[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        b[i] = m % arr[i];
        m -= b[i];
        m /= arr[i];
    }
    for (int i = 1; i <= n; ++i) {
        cout << b[i] << " ";
    }


    return 0;
}
