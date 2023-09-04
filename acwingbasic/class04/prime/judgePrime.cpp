#include "bits/stdc++.h"

#define ll long long
using namespace std;

bool judge(int x) {
    if (x < 2)return false;
    for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int tp;
        cin >> tp;
        if (judge(tp)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }
    return 0;
}
