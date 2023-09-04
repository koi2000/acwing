#include<bits/stdc++.h>

#define ll long long
#define pii pair<int,int>
using namespace std;
const int N = 50010;
int f[N];
int a[N];
int b[N];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        f[0] = -1e5;
        for (int i = 1, s = 0; i <= n; ++i) {
            s = max(s, 0) + a[i];
            f[i] = max(s, f[i - 1]);
        }
        b[n + 1] = -1e5;
        for (int i = n, s = 0; i >= 0; --i) {
            s = max(s, 0) + a[i];
            b[i] = max(s, b[i + 1]);
        }
        int res = INT_MIN;
        for (int i = 1; i < n; i++) {
            res = max(res, f[i] + b[i + 1]);
        }
        cout << res << endl;
    }
    return 0;
}
