#include "bits/stdc++.h"

#define ll long long
using namespace std;

int qpow(int a, int b) {

    int res = 1;
    while (b) {
        if (b & 1) {
            res = res * a;
            if (res > 1e9) {
                return -1;
            }
        }
        if (a >= sqrt(1e9) && b >= 2) {
            return -1;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    cout << qpow(a, b);
    return 0;
}
