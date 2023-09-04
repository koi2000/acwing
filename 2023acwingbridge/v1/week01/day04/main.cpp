#include "bits/stdc++.h"

#define ll long long
using namespace std;
const int maxn = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    int l = 0, r = 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != 'x') {
            l = i, r = i;
        } else {
            r++;
            if (r - l >= 3) {
                r++;
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
